/* { dg-do compile } */
/* { dg-options "-fsanitize=address -c -O3 -fdump-tree-optimized" } */

int x;

static inline
__attribute__((no_sanitize("address")))
void do_not_sanitize(void)
{
  x++;
}

void
sanitize_this(void)
{
  x++;
  do_not_sanitize();
}

/* { dg-final { scan-tree-dump-times "Function do_not_sanitize" 1 "optimized" } } */
