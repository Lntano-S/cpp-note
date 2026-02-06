#include <iostream>
#include <vector>

void get_stats(const std::vector<double> &scores, double &max_score, double &min_score, double &total) {

	for (double score: scores) {
		if (score > max_score) {
			max_score = score;
		}
		
		if (score < min_score) {
			min_score = score;
		}
		
		total += score;
	}
}

int main(void) {
	std::vector<double> scores = {80.0, 90.0, 100.0, 50.0};
	double max_score = scores[0];
	double min_score = scores[0];
	double total = 0;
	
	get_stats(scores, max_score, min_score, total);
	
	std::cout << "最高分：" << max_score << std::endl;
	std::cout << "最低分：" << min_score << std::endl;
	std::cout << "班级总分：" << total << std::endl;
	
	return 0;
}