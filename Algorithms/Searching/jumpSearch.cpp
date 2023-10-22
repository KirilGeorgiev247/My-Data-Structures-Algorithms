int jumpSearch(const int* arr, int len, const int searched) {
	int step = sqrt(len);
	int prev = 0;

	while (arr[min(step, len) - 1] < searched) {
		if (step >= len) {
			return -1;
		}

		prev = step;
		step += sqrt(len);
	}

	while (arr[prev] < searched) {
		prev++;
		if (prev == min(step, len)) {
			return -1;
		}
	}

	if (arr[prev] == searched) {
		return prev;
	}

	return -1;
}