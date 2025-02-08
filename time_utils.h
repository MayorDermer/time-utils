/**
 * @file time_utils.h
 * @brief Time utilities for cpp
 */

#ifndef TIME_UTILS
#define TIME_UTILS

#include <chrono>

// get time now with chosen clock
#define now() std::chrono::high_resolution_clock::now()

 /**
 * @brief Measure time of execution of a body of code
 * @param body The code to measure
 * @return std::chrono::duration ellapsed
 */
#define __time(body) [&]() -> auto { \
	auto start = now(); \
	body \
	auto end = now(); \
	return (end - start); \
}()


 /**
 * @brief Measure time of execution of a body of code in nanoseconds
 * @param body The code to measure
 * @return double nanoseconds passed
 */
#define _time_ns(body) std::chrono::duration_cast<std::chrono::nanoseconds>(__time(body)).count()

 /**
 * @brief Measure time of execution of a body of code in microseconds
 * @param body The code to measure
 * @return double microseconds passed
 */
#define _time_us(body) (_time_ns(body) / 1e3)

 /**
 * @brief Measure time of execution of a body of code in milliseconds
 * @param body The code to measure
 * @return double milliseconds passed
 */
#define _time_ms(body) (_time_ns(body) / 1e6)

 /**
 * @brief Measure time of execution of a body of code in milliseconds
 * @param body The code to measure
 * @return double seconds passed
 */
#define _time_s(body) (_time_ns(body) / 1e9)


 /**
 * @breif returns time elapsed in nanoseconds of given code for x reps (double) CODE IS RUN BY REFERENCE
 * @param body1 first block of code to measure
 * @param reps number of repetitions
 */
#define _time_reps_r(body, reps) [&]() -> double { \
	auto start = now(); \
	for (int i = 0; i < reps; i++) { body } \
	auto end = now(); \
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); \
}()


/**
* @breif same as _time_reps_r but code is run by value
*/
#define _time_reps_v(body, reps)[=]() mutable -> size_t { \
	auto start = now(); \
	for (int i = 0; i < reps; i++) { body } \
	auto end = now(); \
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); \
}()

/**
* @breif return mean runtime of given code over x reps (double) CODE IS RUN BY REFERENCE
*/
#define _time_average_r(body, reps) (_time_reps_r(body, reps) / reps)

/**
* @breif return mean runtime of given code over x reps (double) CODE IS RUN BY VALUE
*/
#define _time_average_v(body, reps) (_time_reps_v(body, reps) / reps)

#endif // !TIME_UTILS
