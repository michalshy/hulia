workspace "Hulia"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hulia"
    location "Hulia"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "%{prj.name}/third_party/spdlog/include;"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions "/utf-8"

        defines
        {
            "HA_PLATFORM_WINDOWS",
            "HA_BUILD_DLL"
        }

    filter "configurations:Debug"
        defines "HA_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "HA_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HA_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "Hulia/third_party/spdlog/include;",
        "Hulia/src;"
    }

    links
    {
        "Hulia"
    }


    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions "/utf-8"

        defines
        {
            "HA_PLATFORM_WINDOWS"
        }
        postbuildcommands
        {
            "{COPYFILE} ../bin/" .. outputdir .. "/Hulia/Hulia.dll ../bin/" .. outputdir .. "/Sandbox"
        }

    filter "configurations:Debug"
        defines "HA_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "HA_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HA_DIST"
        optimize "On"
