workspace "Engine"
	architecture "x64"
	targetdir "build"
	
	configurations 
	{ 
		"Debug", 
        "Release",
        "Dist"
    }
    
    startproject "Sandbox"
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root folder (solution directory)

IncludeDir = {}
IncludeDir["GLFW"]  = "Engine/vendor/GLFW/include"
IncludeDir["Glad"]  = "Engine/vendor/Glad/include"
IncludeDir["ImGui"] = "Engine/vendor/ImGui"


group "Dependencies"
include "Engine/vendor/GLFW"
include "Engine/vendor/Glad"
include "Engine/vendor/ImGui"

group ""


group "Core"
project "Engine"
    location "Engine"
    kind "StaticLib"
    language "C++"
    
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.h"
	pchsource "Engine/src/pch.cpp"

	files 
	{ 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.c", 
		"%{prj.name}/src/**.hpp", 
		"%{prj.name}/src/**.cpp" 

    }

    includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"

	}
    
    links
    {
        "opengl32.lib",
        "GLFW",
        "Glad",
        "ImGui",

    }

	filter "system:windows"
		cppdialect "C++17"
        staticruntime "On"
        
		defines 
		{ 
            "RE_PLATFORM_WINDOWS",
		}
					
    filter "configurations:Debug"
        defines "RE_DEBUG"
        symbols "On"
                
    filter "configurations:Release"
        defines "RE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "RE_DIST"
        optimize "On"

group ""

group "Tools"
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	dependson 
	{ 
		"Engine"
    }
    
	files 
	{ 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.c", 
		"%{prj.name}/src/**.hpp", 
		"%{prj.name}/src/**.cpp" 

	}
    
	includedirs 
	{
        "%{prj.name}/src",
        "Engine/src",
        "Engine/vendor",
    }
	
	filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        
		links 
		{ 
			"Engine"
		}
        
		defines 
		{ 
            "RE_PLATFORM_WINDOWS",
		}
    
    filter "configurations:Debug"
        defines "RE_DEBUG"
        symbols "On"
        
        links
        {
            "Engine/vendor/ImGui/bin/Debug-windows-x86_64/ImGui/ImGui.lib",
        }

    filter "configurations:Release"
        defines "RE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "RE_DIST"
        optimize "On"
group ""


-- "Engine/vendor/ImGui/bin/Debug-windows-x86_64/ImGui/ImGui.lib",