workspace "Hazel"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "Hazel"
	location "Hazel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}" )
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}" )

	pchheader "pch.h"
	pchsource "Hazel/src/pch.cpp"

	targetHazel = "%{cfg.buildtarget.relpath}"
	files
	{ 
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}


	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_DLL"
		}

		filter "configurations:Debug"
			defines "HZ_DEBUG"
			symbols "On"
		
		filter "configurations:Release"
			defines "HZ_RELEASE"
			symbols "On"

		filter "configurations:Dist" 
			defines "HZ_DIST"
			symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}" )
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}" )

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hazel/vendor/spdlog/include",
		"Hazel/src"
	}
	links
	{
		"Hazel"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HZ_PLATFORM_WINDOWS"
		}

		prebuildmessage (" Sandbox Copying ../bin/" .. outputdir .. "/Hazel/Hazel.dll ../bin/" .. outputdir .. "/Sandbox ")
		prebuildcommands
		{
			("{COPY} ../bin/" .. outputdir .. "/Hazel/Hazel.dll ../bin/" .. outputdir .. "/Sandbox")
		}
		


		filter "configurations:Debug"
			defines "HZ_DEBUG"
			symbols "On"
		
		filter "configurations:Release"
			defines "HZ_RELEASE"
			symbols "On"

		filter "configurations:Dist"
			defines "HZ_DIST"
			symbols "On"

-- This function includes GLFW's header files
function includeGtest()
	includedirs "vendor/3partyLib/gtest/include"
end	

-- This function links statically against GLFW
function linkGtest()
	libdirs "vendor/3partyLib/gtest/lib"
	links "gtest"
	defines "_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"

end

project "Test"
	location "Test"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}" )
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}" )

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}


	includedirs
	{
		"Hazel/vendor/spdlog/include",
		"Hazel/src"
	}
	links
	{
		"Hazel"
	}
	includeGtest()
	linkGtest()

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HZ_PLATFORM_WINDOWS",
			"GTEST_LANG_CXX11=1"
		}