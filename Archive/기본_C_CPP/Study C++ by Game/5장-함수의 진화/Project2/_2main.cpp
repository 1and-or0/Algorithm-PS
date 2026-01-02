#include <cstdio>

int findMaxValue(int* a, int len)
{
	int max = a[0];

	for (int i = 0; i < len; ++i)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}

	return max;
}

void setMaxMin(int *max, int *min, int* array_, int len)
{
	int t_max, t_min;
	if (max != NULL && min != NULL)
	{
		t_max = array_[0], t_min = array_[len-1];
	}
	
	for (int i = 0; i < len; ++i)
	{
		if (t_max < array_[i])
		{
			t_max = array_[i];
		}

		if (t_min > array_[i])
		{
			t_min = array_[i];
		}
	}

	*max = t_max;
	*min = t_min;
}

int _2main()
{
	int list[5] = { 1, 2, 3, 4, 5 };

	int max = findMaxValue(list, 5);
	int min;

	int list2[5] = { 11, 242, 32, 41, 53 };
	

	setMaxMin(&max, &min, list2, 5);
	printf("min: %d\n", min);


	return 0;
}