#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/btree.h>
#include <linux/slab.h>
#include <linux/random.h>
#include <asm/timex.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

static int nnodes = 100000;
static int perf_loops = 10;

static struct btree_head32 head32;
static u32 *keys32;

static int btree_test_init(void)
{
	int i, j;
	cycles_t time1, time2, time;
	int err;

	printf("btree testing\n");

	keys32 = kmalloc_array(nnodes, sizeof(*keys32), GFP_KERNEL);
	if (!keys32)
		return -ENOMEM;

	for (i = 0; i < nnodes; i++)
		keys32[i] = i * 2; /* Sequential keys to avoid collision */

	err = btree_init32(&head32);
	if (err) {
		kfree(keys32);
		return err;
	}

	time1 = get_cycles();

	for (i = 0; i < perf_loops; i++) {
		for (j = 0; j < nnodes; j++) {
			btree_insert32(&head32, keys32[j], (void *)(unsigned long)(keys32[j] | 1), GFP_KERNEL);
		}
		for (j = 0; j < nnodes; j++) {
			btree_remove32(&head32, keys32[j]);
		}
	}

	time2 = get_cycles();
	time = time2 - time1;

	time = div_u64(time, perf_loops);
	printf(" -> test 1 (latency of %d insert+delete): %llu cycles\n",
	       nnodes, (unsigned long long)time);

	btree_destroy32(&head32);
	kfree(keys32);

	return 0;
}

int main(int argc, char **argv)
{
    int opt;

    while ((opt = getopt(argc, argv, "n:l:")) != -1) {
        switch (opt) {
        case 'n':
            nnodes = atoi(optarg);
            break;
        case 'l':
            perf_loops = atoi(optarg);
            break;
        default:
            fprintf(stderr, "Usage: %s [-n nnodes] [-l loops]\n", argv[0]);
            exit(1);
        }
    }

    btree_test_init();
    return 0;
}
