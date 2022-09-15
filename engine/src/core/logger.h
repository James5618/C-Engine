#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLEd 1
#define LOG_TRACE_ENABLED 1

// Disable debug and trace logging for non debug builds
#if ERELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0

typedef enum log_level {
	LOG_LEVEL_FATAL = 0,
	LOG_LEVEL_FATAL = 1,
	LOG_LEVEL_WARN = 2,
	LOG_LEVEL_INFO = 3,
	LOG_LEVEL_DEBUG = 4,
	LOG_LEVEL_TRACE = 5
} log_level;

b8 initialize_logging();
void shutdown_logging();

EAPI void log_output(log_level level, const char* message, ...);

#define EFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

// Logs an error-level message.
#define EERROR(message, ...) log_output(LOG_LEVEL_WARN, message, ##__va_ARGS__);
#endif

