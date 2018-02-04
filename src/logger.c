#include "logger.h"

void logger_init(struct Logger* log, int level)
{
  logger_set_level(log, level);
  logger_set_stream(log, stdout);
}

void logger_set_level(struct Logger* log, int level)
{
  log->level = level;
}

void logger_set_stream(struct Logger* log, FILE* stream)
{
  log->output = stream;
}

int _logger_generic(struct Logger* log, int level,
  const char* prefix,
  const char* file_name, int line_num,
  const char* fmt, ...)
{
  if (log->level <= level)
  {
    fprintf(log->output, "%s %s: %d -- ", prefix, file_name, line_num);
    va_list args;
    int count;
    va_start(args, fmt);
    count = vfprintf(log->output, fmt, args);
    va_end(args);
    return count;
  }
  return 0;
}
