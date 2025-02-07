/**
 * @file time_utils.h
 * @brief Time utilities for cpp
 */

#ifndef TIME_UTILS
#define TIME_UTILS

#include <chrono>

 /**
  * @brief Measure time of execution of a body of code
  * @param body The code to measure
  * @return std::chrono::duration ellapsed
  */
#define __time(body) [&]() -> auto { \
	auto start = std::chrono::high_resolution_clock::now(); \
	body \
	auto end = std::chrono::high_resolution_clock::now(); \
	return (end - start); \
}()

  /**
   * @brief Measure time of execution of a body of code in nanoseconds
   * @param body The code to measure
   * @return double nanoseconds passed
   */
#define _time_ns(body) [&]() -> double { \
	return std::chrono::duration_cast<std::chrono::nanoseconds>(__time(body)).count(); \
}()

   /**
	* @brief Measure time of execution of a body of code in microseconds
	* @param body The code to measure
	* @return double microseconds passed
	*/
#define _time_us(body) [&]() -> double {   \
	return (_time_ns(body) / 1e3); \
}()

	/**
	 * @brief Measure time of execution of a body of code in milliseconds
	 * @param body The code to measure
	 * @return double milliseconds passed
	 */
#define _time_ms(body) [&]() -> double {   \
	return (_time_ns(body) / 1e6); \
}()

	 /**
	  * @brief Measure time of execution of a body of code in milliseconds
	  * @param body The code to measure
	  * @return double seconds passed
	  */
#define _time_s(body) [&]() -> double {    \
	return (_time_ns(body) / 1e9); \
}()


#endif // !TIME_UTILS
