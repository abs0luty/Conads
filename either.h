#ifndef _CONADS_EITHER_H_
#define _CONADS_EITHER_H_

#include <stdbool.h>

#define DecEither(T, ET)                                                       \
  typedef struct Either##T {                                                   \
    T *value;                                                                  \
    ET *error;                                                                 \
  } Either##T

#define Ok(T, v)                                                               \
  Either##T { .value = v, .error = (void *)0 }

#define Err(T, ET, e)                                                          \
  Either##T { .value = (void *)0, .error = e }

#define bindEither(T, fn, m) (m.error != (void *)0) ? m : Ok(T, fn(m.value))

#endif /* _CONADS_EITHER_H_ */