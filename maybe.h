#ifndef _CONADS_MAYBE_H_
#define _CONADS_MAYBE_H_

#define DecMaybe(T)                                                            \
  typedef struct Maybe##T {                                                    \
    T value;                                                                   \
    bool has_value;                                                            \
  } Maybe##T;

#define Nothing(T)                                                             \
  Maybe##T { .has_value = false }

#define Just(T, v)                                                             \
  Maybe##T { .value = v, .has_value = true }

#define bindMaybe(T, fn, m) m.has_value ? Just(T, fn(m.value)) : Nothing(T);

#endif /* _CONADS_MAYBE_H_ */