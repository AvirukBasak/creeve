/*
 * WARNING 1:
 * All functions MUST be prefixed w/ sys_
 * Example: prototype for function that checks if system is windows
 *  string sys_is_Windows()
 *
 * WARNING 2:
 * If a function uses *alloc, it's the job of the caller to free the memory.
 * Such a function HAS TO in its doc ask the caller to clear up the memory.
 * Same goes for closing of files (created file pointers);
 */

# include "../headers/headers.h"
# include "../headers/errcodes.h"

# ifndef SYSTEM_H

    # define SYSTEM_H 1

    /**
     * @brief Returns true if compilation platform is Windows
     *
     * @return bool True if Windows
     */
    bool sys_is_Windows();

     /**
     * @brief Returns true if compilation platform is Linux
     *
     * @return bool True if Linux
     */
    bool sys_is_Linux();

    /**
     * @brief Returns true if compilation platform is FreeBSD
     *
     * @return bool True if FreeBSD
     */
    bool sys_is_FreeBSD();

    /**
     * @brief Returns true if compilation platform is Android
     *
     * @return bool True if Android
     */
    bool sys_is_android();

     /**
     * @brief Returns true if compilation platform is macOS
     *
     * @return bool True if macOS
     */
    bool sys_is_macOS();

     /**
     * @brief Returns true if compilation platform is Unix
     *
     * @return bool True if Unix
     */
    bool sys_is_Unix();

# endif
