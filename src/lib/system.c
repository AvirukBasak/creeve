# include "system.h"

/**
 * @brief Returns true if compilation platform is Windows
 *
 * @return bool True if Windows
 */
bool sys_is_Windows()
{
    # if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(_WIN64)
        return true;
    # endif
    return false;
}

/**
 * @brief Returns true if compilation platform is Linux
 *
 * @return bool True if Linux
 */
bool sys_is_Linux()
{
    # if defined(linux) || defined(__linux__) || defined (__linux)
        return true;
    # endif
    return false;
}

/**
 * @brief Returns true if compilation platform is FreeBSD
 *
 * @return bool True if FreeBSD
 */
bool sys_is_FreeBSD()
{
    # if defined(__FreeBSD__)
        return true;
    # endif
    return false;
}

/**
 * @brief Returns true if compilation platform is Android
 *
 * @return bool True if Android
 */
bool sys_is_android()
{
    # if defined(__ANDROID__)
        return true;
    # endif
    return false;
}

/**
 * @brief Returns true if compilation platform is macOS
 *
 * @return bool True if macOS
 */
bool sys_is_macOS()
{
    # if defined(__APPLE__) || defined(__MACH__)
        // # include <TargetConditionals.h>
        // # ifdef TARGET_OS_MAC
            return true;
        // # endif
    # endif
    return false;
}

/**
 * @brief Returns true if compilation platform is Unix
 *
 * @return bool True if Unix
 */
bool sys_is_Unix()
{
    bool is_unix = false;
    # if defined(unix) || defined(__unix__) || defined (__unix)
        is_unix = true;
    # endif
    return is_unix || sys_is_Linux() || sys_is_macOS() || sys_is_FreeBSD() || sys_is_android();
}
