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
    
local outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"%{prj.name}/**.h", 
		"%{prj.name}/**.c", 
		"%{prj.name}/**.hpp", 
		"%{prj.name}/**.cpp" 
    }

    includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor",
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
		"%{prj.name}/**.h", 
		"%{prj.name}/**.c", 
		"%{prj.name}/**.hpp", 
		"%{prj.name}/**.cpp" 
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
                
    filter "configurations:Release"
        defines "RE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "RE_DIST"
        optimize "On"
group ""