//part 1
//
//#include <iostream>
//#include <vector>
//#include <random>
//#include <Windows.h>
//#undef max
////new lib
//#include <string>
//#include <sstream>
//#include <algorithm>
//#include <tuple>
//using namespace std;
//
//template <typename T>
//void remove(std::vector<T>& v, size_t index) {
//	v.erase(v.begin() + index);
//}
//
//int rand(int n)
//{
//	std::random_device rd;
//	std::mt19937 generator(rd());
//	std::uniform_int_distribution<> distribution(-n, n);
//	return distribution(generator);
//}
//
//struct Elements_Of_Puzzle {
//	int rt, ft, lt, bk;
//	bool color;
//	void print() {
//		std::cout << rt << " " << ft << " " << lt << " " << bk << "           ";
//	}
//	void set(int n) {
//		do { rt = rand(n); } while (rt == 0);
//		do { ft = rand(n); } while (ft == 0);
//		do { lt = rand(n); } while (lt == 0);
//		do { bk = rand(n); } while (bk == 0);
//		color = rand(n) % 2;
//	}
//};
//
//void PrintElementColor(vector<vector<Elements_Of_Puzzle>> puzzle, int i, int j) {
//	HANDLE color_out = GetStdHandle(STD_OUTPUT_HANDLE);
//	if (puzzle[i][j].color) SetConsoleTextAttribute(color_out, 0x88);
//	else SetConsoleTextAttribute(color_out, 0xFF);
//	std::cout << "  ";
//	SetConsoleTextAttribute(color_out, 15);
//}
//
//void PrintPicture(int M, vector<vector<Elements_Of_Puzzle>> puzzle)
//{
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < M; j++) {
//			PrintElementColor(puzzle, i, j);
//		}
//		std::cout << std::endl;
//	}
//}
//
//bool Check_Border(vector<vector<Elements_Of_Puzzle>> puzzleB, vector<vector<Elements_Of_Puzzle>> total)
//{
//	for (int i = 0; i < total.size(); ++i) {
//		for (int j = 0; j < total.size(); ++j) {
//			if (puzzleB[i][j].lt != total[i][j].lt || puzzleB[i][j].ft != total[i][j].ft || puzzleB[i][j].bk != total[i][j].bk || puzzleB[i][j].rt != total[i][j].rt) {
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//vector<Elements_Of_Puzzle> Swap_Structures(vector <Elements_Of_Puzzle> puzzle_end, int start)
//{
//	for (int i = start; i < puzzle_end.size(); ++i) {
//		for (int j = i + 1; j < puzzle_end.size(); ++j) {
//			if (puzzle_end[i].lt == puzzle_end[j].lt && puzzle_end[i].ft == puzzle_end[j].ft) {
//				std::swap(puzzle_end[i], puzzle_end[j]);
//				return puzzle_end;
//			}
//		}
//		return puzzle_end;
//	}
//	return puzzle_end;
//}
//
//bool Count(Elements_Of_Puzzle a, vector<vector<Elements_Of_Puzzle>>& total, int k)
//{
//	int count = 0;
//	for (int i = 0; i < total.size(); ++i) {
//		for (int j = 0; j < total.size(); ++j) {
//			if (total[i][j].bk == a.bk && total[i][j].rt == a.rt && total[i][j].lt == a.lt && total[i][j].ft == a.ft && total[i][j].color == a.color) {
//				++count;
//			}
//		}
//	}
//	return (count < k);
//}
//
//bool Count_Puzzle(Elements_Of_Puzzle a, vector<vector<Elements_Of_Puzzle>>& puzzle, vector<vector<Elements_Of_Puzzle>>& total)
//{
//	int PCount = 0;
//	for (int i = 0; i < puzzle.size(); ++i) {
//		for (int j = 0; j < puzzle.size(); ++j) {
//			if (puzzle[i][j].bk == a.bk && puzzle[i][j].rt == a.rt && puzzle[i][j].lt == a.lt && puzzle[i][j].ft == a.ft && puzzle[i][j].color == a.color) {
//				++PCount;
//			}
//		}
//	}
//	return Count(a, total, PCount);
//}
//
//bool NULL_FIND(vector<vector<Elements_Of_Puzzle>> total)
//{
//	int M = total.size();
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < M; ++j) {
//			if (total[i][j].bk == 0 && total[i][j].lt == 0 && total[i][j].ft == 0 && total[i][j].rt == 0) {
//				return false;
//			}
//		}
//	}
//	for (int i = 0; i < M - 1; ++i) {
//		for (int j = 0; j < M; ++j) {
//			if (total[i + 1][j].ft != -total[i][j].bk) {
//				return false;
//			}
//		}
//	}
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < M - 1; ++j) {
//			if (total[i][j + 1].lt != -total[i][j].rt) {
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//bool Find_Center(vector<Elements_Of_Puzzle> puzzle_end, vector<vector<Elements_Of_Puzzle>>& total, vector<vector<Elements_Of_Puzzle>>& puzzle)
//{
//	bool flag = false;
//	for (int i = 1; i < total.size() - 1; ++i) {
//		for (int j = 1; j < total.size() - 1; ++j) {
//			flag = false;
//			if (total[i][j].bk == 0 && total[i][j].rt == 0 && total[i][j].lt == 0 && total[i][j].ft == 0) {
//				for (int k = 0; k < puzzle_end.size(); ++k) {
//					if (puzzle_end[k].lt == -total[i][j - 1].rt && puzzle_end[k].ft == -total[i - 1][j].bk && puzzle_end[k].color == puzzle[i][j].color && Count_Puzzle(puzzle_end[k], puzzle, total)) {
//						total[i][j] = puzzle_end[k];
//						flag = true;
//						break;
//					}
//				}
//				if (flag == false) {
//					break;
//				}
//			}
//		}
//		if (flag == false) {
//			break;
//		}
//	}
//	flag = NULL_FIND(total);
//	return flag;
//}
//
//bool Find_Border(vector<Elements_Of_Puzzle> puzzle_up, vector<Elements_Of_Puzzle> puzzle_left, vector<Elements_Of_Puzzle> puzzle_down, vector<Elements_Of_Puzzle> puzzle_right, vector<vector<Elements_Of_Puzzle>>& total, vector<vector<Elements_Of_Puzzle>>& puzzle, vector<vector<Elements_Of_Puzzle>>& puzzleB)
//{
//	auto rng = std::default_random_engine{};
//	int M = puzzle_up.size();
//	int index_column_up = 0;
//	int index_string_left = 0;
//	int index_column_down = 0;
//	int index_string_right = 0;
//	int count = 0; int cnt = 0;
//	vector<Elements_Of_Puzzle> puzzle_up1(M, Elements_Of_Puzzle{});
//	vector<Elements_Of_Puzzle> puzzle_down1(M, Elements_Of_Puzzle{});
//	vector<Elements_Of_Puzzle> puzzle_right1(M, Elements_Of_Puzzle{});
//	vector<Elements_Of_Puzzle> puzzle_left1(M, Elements_Of_Puzzle{});
//	while (count != M * M) {
//		for (int i = 0; i < puzzle_up.size(); ++i) {
//			if (puzzle_up[i].lt == -total[0][index_column_up].rt && index_column_up < M - 2 && puzzle_up[i].color == puzzle[0][index_column_up + 1].color /*&& Count_Puzzle(puzzle_up[i], puzzle, total)*/) {
//				++index_column_up;
//				total[0][index_column_up] = puzzle_up[i];
//				puzzle_up1.push_back(puzzle_up[i]);
//				remove(puzzle_up, i);
//			}
//		}
//		++count;
//	}
//	count = 0;
//	while (count != M * M) {
//		for (int i = 0; i < puzzle_left.size(); ++i) {
//			if (puzzle_left[i].ft == -total[index_string_left][0].bk && index_string_left < M - 2 && puzzle_left[i].color == puzzle[index_string_left + 1][0].color /*&& Count_Puzzle(puzzle_left[i], puzzle, total)*/) {
//				++index_string_left;
//				total[index_string_left][0] = puzzle_left[i];
//				puzzle_left1.push_back(puzzle_left[i]);
//				remove(puzzle_left, i);
//			}
//		}
//		++count;
//	}
//	count = 0;
//	while (count != M * M) {
//		for (int i = 0; i < puzzle_down.size(); ++i) {
//			if (puzzle_down[i].lt == -total[M - 1][index_column_down].rt && index_column_down < M - 2 && puzzle_down[i].color == puzzle[M - 1][index_column_down + 1].color/* && Count_Puzzle(puzzle_down[i], puzzle, total)*/) {
//				++index_column_down;
//				total[M - 1][index_column_down] = puzzle_down[i];
//				puzzle_down1.push_back(puzzle_down[i]);
//				remove(puzzle_down, i);
//			}
//		}
//		++count;
//	}
//	count = 0;
//	while (count != M * M) {
//		for (int i = 0; i < puzzle_right.size(); ++i) {
//			if (puzzle_right[i].ft == -total[index_string_right][M - 1].bk && index_string_right < M - 2 && puzzle_right[i].color == puzzle[index_string_right + 1][M - 1].color /*&& Count_Puzzle(puzzle_right[i], puzzle, total)*/) {
//				++index_string_right;
//				total[index_string_right][M - 1] = puzzle_right[i];
//				puzzle_right1.push_back(puzzle_right[i]);
//				remove(puzzle_right, i);
//			}
//		}
//		count += 1;
//	}
//	puzzle_up = puzzle_up1;
//	puzzle_left = puzzle_left1;
//	puzzle_right = puzzle_right1;
//	puzzle_down = puzzle_down1;
//	index_column_up = 1;
//	index_string_left = 1;
//	index_column_down = 1;
//	index_string_right = 1;
//	bool flag = true;
//	while (index_column_up != M - 1 && index_string_right != M - 1 && index_string_left != M - 1 && index_column_down != M - 1) {
//		if (total[0][index_column_up].bk == 0) {
//			return false;
//		}
//		else { ++index_column_up; }
//		if (total[index_string_left][0].rt == 0) {
//			return false;
//		}
//		else { ++index_string_left; }
//		if (total[M - 1][index_column_down].ft == 0 && total[M - 1][M - 2].rt != -total[M - 1][M - 1].lt) {
//			return false;
//		}
//		else { ++index_column_down; }
//		if (total[index_string_right][M - 1].lt == 0 && total[M - 1][M - 1].ft != -total[M - 2][M - 1].bk) {
//			return false;
//		}
//		else { ++index_string_right; }
//	}
//	return Check_Border(puzzleB, total);
//}
//
//vector<vector<Elements_Of_Puzzle>> Angles(vector<vector<Elements_Of_Puzzle>> puzzle2, vector<vector<Elements_Of_Puzzle>> total) //Функция для забива углов.
//{
//	int M = total.size();
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < M; ++j) {
//			if (puzzle2[i][j].ft == 0 && puzzle2[i][j].lt == 0 && puzzle2[i][j].bk != 0 && puzzle2[i][j].rt != 0) {
//				total[0][0] = puzzle2[i][j];
//			}
//			if (puzzle2[i][j].ft == 0 && puzzle2[i][j].rt == 0 && puzzle2[i][j].bk != 0 && puzzle2[i][j].lt != 0) {
//				total[0][M - 1] = puzzle2[i][j];
//			}
//			if (puzzle2[i][j].bk == 0 && puzzle2[i][j].lt == 0 && puzzle2[i][j].ft != 0 && puzzle2[i][j].rt != 0) {
//				total[M - 1][0] = puzzle2[i][j];
//			}
//			if (puzzle2[i][j].rt == 0 && puzzle2[i][j].bk == 0 && puzzle2[i][j].ft != 0 && puzzle2[i][j].lt != 0) {
//				total[M - 1][M - 1] = puzzle2[i][j];
//			}
//		}
//	}
//	return total;
//}
//
//void Puzzle_Print(vector<vector<Elements_Of_Puzzle>> puzzle)
//{
//	for (int i = 0; i < puzzle.size(); ++i) {
//		for (int j = 0; j < puzzle.size(); ++j) {
//			puzzle[i][j].print();
//			std::cout << "\t";
//		}
//		std::cout << std::endl;
//	}
//}
//
//static class Puzzle_Utility
//{
//public:
//	static void Print_Element(const Elements_Of_Puzzle& element);
//	// Output to the console element from puzzle in the format:
//	// *  ft  *
//	// lt     rt
//	// *  bk  *
//	static void Print_Puzzle(const std::vector<std::vector<Elements_Of_Puzzle>>& puzzle);
//	// Output to the console of all puzzle in the format:
//	// *  ft  *		*  ft  *		*  ft  *		*  ft  *
//	// lt     rt	lt     rt		lt     rt		lt     rt
//	// *  bk  *		*  bk  *		*  bk  *		*  bk  *
//	//
//	// *  ft  *		*  ft  *		*  ft  *		*  ft  *
//	// lt     rt	lt     rt		lt     rt		lt     rt
//	// *  bk  *		*  bk  *		*  bk  *		*  bk  *
//	//
//	// *  ft  *		*  ft  *		*  ft  *		*  ft  *
//	// lt     rt	lt     rt		lt     rt		lt     rt
//	// *  bk  *		*  bk  *		*  bk  *		*  bk  *
//};
//	
//void Puzzle_Utility::Print_Element(const Elements_Of_Puzzle& element)
//{
//	if (nullptr == &element) return;
//	vector<vector<Elements_Of_Puzzle>> puzzle(1, vector<Elements_Of_Puzzle>(1, element));
//	Print_Puzzle(puzzle);
//}
//void Puzzle_Utility::Print_Puzzle(const std::vector<std::vector<Elements_Of_Puzzle>>& puzzle)
//{
//	HANDLE color_out = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	if (nullptr == &puzzle) return;
//
//	int M = int(puzzle.size());
//	int max_len_rt = 0;
//	int max_len_ft = 0;
//	int max_len_lt = 0;
//	int max_len_bk = 0;
//
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < M; j++) {
//			max_len_rt = std::max(max_len_rt, int(to_string(puzzle[i][j].rt).length()));
//			max_len_ft = std::max(max_len_ft, int(to_string(puzzle[i][j].ft).length()));
//			max_len_lt = std::max(max_len_lt, int(to_string(puzzle[i][j].lt).length()));
//			max_len_bk = std::max(max_len_bk, int(to_string(puzzle[i][j].bk).length()));
//		}
//	}
//
//	const int BASE_GAP_LENGHT = 6;
//	int gap_lenght = BASE_GAP_LENGHT;
//	int max_len_ft_lt = std::max(max_len_rt, max_len_ft);
//	int max_len_bk_rt = std::max(max_len_bk, max_len_rt);
//	if (max_len_ft_lt >= BASE_GAP_LENGHT)
//		gap_lenght = BASE_GAP_LENGHT + BASE_GAP_LENGHT * (max_len_ft_lt / BASE_GAP_LENGHT);
//	if (max_len_bk_rt >= BASE_GAP_LENGHT)
//		gap_lenght = BASE_GAP_LENGHT + 2 + BASE_GAP_LENGHT * (max_len_ft_lt / BASE_GAP_LENGHT);
//
//	const int SPACE_LENGHT = 5;
//	const char BORDER = '*';
//	int curr_len;
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < M; j++) {
//			std::cout << BORDER;
//			curr_len = int(to_string(puzzle[i][j].ft).length());
//			for (int k = 0; k < gap_lenght / 2 - curr_len / 2; k++)
//				std::cout << ' ';
//			std::cout << puzzle[i][j].ft;
//			for (int k = 0; k < gap_lenght / 2 - (curr_len - 1) / 2; k++)
//				std::cout << ' ';
//			std::cout << BORDER;
//			for (int k = 0; k < SPACE_LENGHT; k++)
//				std::cout << ' ';
//		}
//		std::cout << '\n';
//		// пробел по центру
//		for (int j = 0; j < M; j++) {
//			curr_len = int(to_string(puzzle[i][j].lt).length()) + int(to_string(puzzle[i][j].rt).length());
//			std::cout << puzzle[i][j].lt;
//			// изменение цвета вывода
//			if (puzzle[i][j].color == 0) { SetConsoleTextAttribute(color_out, 0xFF); }
//			else { SetConsoleTextAttribute(color_out, 0x88); }
//			for (int k = 0; k < gap_lenght + 3 - curr_len; k++)
//				std::cout << ' ';
//			// обратный цвет
//			SetConsoleTextAttribute(color_out, 15);
//			std::cout << puzzle[i][j].rt;
//
//			for (int k = 0; k < SPACE_LENGHT; k++)
//				std::cout << ' ';
//
//
//
//		}
//		std::cout << '\n';
//
//		for (int j = 0; j < M; j++) {
//			std::cout << BORDER;
//			curr_len = int(to_string(puzzle[i][j].bk).length());
//			for (int k = 0; k < gap_lenght / 2 - curr_len / 2; k++)
//				std::cout << ' ';
//			std::cout << puzzle[i][j].bk;
//			for (int k = 0; k < gap_lenght / 2 - (curr_len - 1) / 2; k++)
//				std::cout << ' ';
//			std::cout << BORDER;
//			for (int k = 0; k < SPACE_LENGHT; k++)
//				std::cout << ' ';
//		}
//		std::cout << "\n\n";
//	}
//}
//
//int main()
//{
//
//	auto rng = std::default_random_engine{};
//	int N; std::cout << "Enter N: "; std::cin >> N;
//	int M; std::cout << "Enter M: "; std::cin >> M;
//	std::random_device rd;
//	std::mt19937 generator(rd());
//	std::uniform_int_distribution<> distribution(0, N - 1);
//	vector<vector<Elements_Of_Puzzle>> puzzle(M, vector<Elements_Of_Puzzle>(M, Elements_Of_Puzzle{}));
//	vector<vector<Elements_Of_Puzzle>> puzzle2(M, vector<Elements_Of_Puzzle>(M, Elements_Of_Puzzle{}));
//	vector<vector<Elements_Of_Puzzle>> puzzle_border(M, vector<Elements_Of_Puzzle>(M, Elements_Of_Puzzle{}));
//	vector<Elements_Of_Puzzle> puzzle_;
//	vector<vector<Elements_Of_Puzzle>> total(M, vector<Elements_Of_Puzzle>(M, Elements_Of_Puzzle{}));
//
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < M; ++j) {
//			puzzle[i][j].set(N);
//		}
//	}
//	for (int j = 0; j < M; ++j) {
//		puzzle[0][j].ft = 0;
//		puzzle[j][0].lt = 0;
//		puzzle[M - 1][j].bk = 0;
//		puzzle[j][M - 1].rt = 0;
//	}
//	for (int i = 0; i < M - 1; ++i) {
//		for (int j = 0; j < M - 1; ++j) {
//			puzzle[i][j].rt = (-1) * puzzle[i][j + 1].lt;
//			puzzle[i][j].bk = (-1) * puzzle[i + 1][j].ft;
//		}
//	}
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < M; ++j) {
//			if (i > 0 && i != M - 1 && j == M - 1) {
//				puzzle[i][j].ft = -puzzle[i - 1][j].bk;
//			}
//			if (i == M - 1 && j > 0 && j != M - 1) {
//				puzzle[i][j].lt = -puzzle[i][j - 1].rt;
//			}
//		}
//	}
//	puzzle[M - 1][M - 1].lt = -puzzle[M - 1][M - 2].rt; puzzle[M - 1][M - 1].ft = -puzzle[M - 2][M - 1].bk;
//	vector<vector<Elements_Of_Puzzle>> puzzleB(M, vector<Elements_Of_Puzzle>(M, Elements_Of_Puzzle{}));
//	for (int i = 0; i < puzzle.size(); ++i) {
//		for (int j = 0; j < puzzle.size(); ++j) {
//			if (puzzle[i][j].ft == 0) {
//				puzzleB[i][j] = puzzle[i][j];
//			}
//			else if (puzzle[i][j].lt == 0) {
//				puzzleB[i][j] = puzzle[i][j];
//			}
//			else if (puzzle[i][j].rt == 0) {
//				puzzleB[i][j] = puzzle[i][j];
//			}
//			else if (puzzle[i][j].bk == 0) {
//				puzzleB[i][j] = puzzle[i][j];
//			}
//		}
//	}
//	Puzzle_Utility::Print_Puzzle(puzzle);
//	PrintPicture(puzzle.size(), puzzle);
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < M; ++j) {
//			puzzle_.push_back(puzzle[i][j]);
//		}
//	}
//	int index = 0;
//	shuffle(puzzle_.begin(), puzzle_.end(), rng);
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < M; ++j) {
//			puzzle2[i][j] = puzzle_[index];
//			++index;
//		}
//	}
//	// Обращение к функции забивки углов.
//	total = Angles(puzzle2, total);
//	std::cout << "\n\n";
//	//Puzzle_Utility::Print_Puzzle(total);
//
//
//	//Забивка полей в новом по пространству
//	vector<Elements_Of_Puzzle> puzzle_end(M * M - 2 * M - 2 * (M - 2), Elements_Of_Puzzle{});
//	int INDEX = 0;
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < M; ++j) {
//			if (puzzle2[i][j].bk != 0 && puzzle2[i][j].ft != 0 && puzzle2[i][j].lt != 0 && puzzle2[i][j].rt != 0) {
//				puzzle_end[INDEX] = puzzle2[i][j];
//				++INDEX;
//			}
//		}
//	}
//	vector<int> repeat;
//	for (int i = 0; i < puzzle_end.size(); ++i) {
//		int h = 1;
//		for (int j = i + 1; j < puzzle_end.size(); ++j) {
//			if (puzzle_end[i].lt == puzzle_end[j].lt && puzzle_end[i].ft == puzzle_end[j].ft) {
//				h += 1;
//			}
//		}
//		if (h > 1) {
//			repeat.push_back(i);
//		}
//	}
//	puzzle_border = Angles(puzzle2, puzzle_border);
//	vector<Elements_Of_Puzzle> puzzle_up(M, Elements_Of_Puzzle{});
//	vector<Elements_Of_Puzzle> puzzle_down(M, Elements_Of_Puzzle{});
//	vector<Elements_Of_Puzzle> puzzle_right(M, Elements_Of_Puzzle{});
//	vector<Elements_Of_Puzzle> puzzle_left(M, Elements_Of_Puzzle{});
//	int left_column = 1;
//	int right_column = 1;
//	int up_string = 1;
//	int down_string = 1;
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < M; ++j) {
//			if (puzzle2[i][j].ft == 0 && puzzle2[i][j].lt != 0 && puzzle2[i][j].rt != 0 && puzzle2[i][j].bk != 0) {
//				puzzle_border[0][up_string] = puzzle2[i][j];
//				puzzle_up[up_string - 1] = puzzle2[i][j];
//				++up_string;
//			}
//			if (puzzle2[i][j].rt == 0 && puzzle2[i][j].lt != 0 && puzzle2[i][j].ft != 0 && puzzle2[i][j].bk != 0) {
//				puzzle_border[right_column][M - 1] = puzzle2[i][j];
//				puzzle_right[right_column - 1] = puzzle2[i][j];
//				++right_column;
//			}
//			if (puzzle2[i][j].bk == 0 && puzzle2[i][j].lt != 0 && puzzle2[i][j].ft != 0 && puzzle2[i][j].rt != 0) {
//				puzzle_border[M - 1][down_string] = puzzle2[i][j];
//				puzzle_down[down_string - 1] = puzzle2[i][j];
//				++down_string;
//			}
//			if (puzzle2[i][j].lt == 0 && puzzle2[i][j].rt != 0 && puzzle2[i][j].ft != 0 && puzzle2[i][j].bk != 0) {
//				puzzle_border[left_column][0] = puzzle2[i][j];
//				puzzle_left[left_column - 1] = puzzle2[i][j];
//				++left_column;
//			}
//		}
//	}
//	//Обращение к функции забивки крайних полей.
//	while (true) {
//		if (Find_Border(puzzle_up, puzzle_left, puzzle_down, puzzle_right, total, puzzle, puzzleB) == true) { break; }
//		else {
//			shuffle(puzzle_up.begin(), puzzle_up.end(), rng);
//			shuffle(puzzle_down.begin(), puzzle_down.end(), rng);
//			shuffle(puzzle_right.begin(), puzzle_right.end(), rng);
//			shuffle(puzzle_left.begin(), puzzle_left.end(), rng);
//		}
//	}
//	vector<vector<Elements_Of_Puzzle>> start = total;
//	std::cout << "\n\n";
//	Puzzle_Utility::Print_Puzzle(total);
//	int g = 0;
//	while (true) {
//		if (Find_Center(puzzle_end, total, puzzle) == true) { break; }
//		else {
//			std::cout << "\n\n";
//			Puzzle_Utility::Print_Puzzle(total);
//			if (repeat.size() != 0) {
//				puzzle_end = Swap_Structures(puzzle_end, repeat[g]);
//			}
//			total = start;
//			if (g < repeat.size()) { ++g; }
//			else { g = 0; }
//		}
//	}
//	std::cout << "\n\n";
//	Puzzle_Utility::Print_Puzzle(total);
//	PrintPicture(puzzle.size(), total);
//}

//part 2

#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <sstream>
#include <Windows.h>
#undef max

namespace Legacy
{
	static bool _int(std::string ptr_v, int& value)
	{
		const int START_ASCII_NUM = (int)'0';
		const int END_ASCII_NUM = (int)'9';
		const int NEGATIVE_ASCII = int('-');

		int total_value = 0;
		int lenght = ptr_v.length();
		bool negative = false;
		int int_deep = 0;
		int curr_int_value = 0;
		char curr_char = '\0';

		for (int i = 0; i < lenght; i++)
		{
			curr_char = ptr_v[i];
			if (!((curr_char >= START_ASCII_NUM && curr_char <= END_ASCII_NUM) || NEGATIVE_ASCII == curr_char))
				return false;

			if (NEGATIVE_ASCII == curr_char && true == negative)
				return false;
			if (NEGATIVE_ASCII == curr_char && 0 == int_deep && false == negative)
				negative = true;

			if (curr_char >= START_ASCII_NUM && curr_char <= END_ASCII_NUM)
			{
				total_value = total_value * 10 + (curr_char - START_ASCII_NUM);
				int_deep++;
			}
		}
		if (negative) total_value *= (-1);
		value = total_value;

		return true;
	}
}

class Utility
{
public:
	// 23 for 4 7
	static int RandomN(int n, int s = 24)
	{
		//static unsigned int seed = s;
		//std::srand(seed++);
		//if (rand() % 2) {
		//	seed++;
		//	return rand() % n;
		//}
		//else {
		//	seed++;
		//	return (-1) * (rand() % n);
		//}

		static std::random_device rd;
		static std::mt19937 generator(rd());
		static std::uniform_int_distribution<> distribution(-n, n);
		return distribution(generator);
	}
};
class Element
{
public:
	int top;
	int bottom;
	int right;
	int left;
	std::size_t index;
	bool color;


	Element()
	{
		top = 0;
		bottom = 0;
		right = 0;
		left = 0;
		index = 0;
		color = false;
	}
	Element(int top, int bottom, int right, int left, bool color)
	{
		this->top = top;
		this->bottom = bottom;
		this->right = right;
		this->left = left;
		this->color = color;
		index = 0;
	}
	Element(int top, int bottom, int right, int left, int index, bool color)
	{
		this->top = top;
		this->bottom = bottom;
		this->right = right;
		this->left = left;
		this->index = index;
		this->color = color;
	}

	Element& RandomSet(int n)
	{
		do { top = Utility::RandomN(n); } while (top == 0);
		do { bottom = Utility::RandomN(n); } while (bottom == 0);
		do { right = Utility::RandomN(n); } while (right == 0);
		do { left = Utility::RandomN(n); } while (left == 0);
		color = Utility::RandomN(n) % 2;
		return *this;
	}

	bool operator==(Element e) {
		if (top == e.top && bottom == e.bottom && left == e.left && right == e.right && color == e.color) {
			return true;
		}
		else {
			return false;
		}
	}
};
class Puzzle
{
private:
	std::vector<std::vector<Element>> puzzle;
	void PrintElementColor(int i, int j) {
		HANDLE color_out = GetStdHandle(STD_OUTPUT_HANDLE);
		if (puzzle[i][j].color) SetConsoleTextAttribute(color_out, 0xFF);
		else SetConsoleTextAttribute(color_out, 0x88);
		std::cout << "  ";
		SetConsoleTextAttribute(color_out, 15);
	}

public:
	std::size_t M;

	Puzzle()
	{
		this->M = 0;
		puzzle = std::vector<std::vector<Element>>(M, std::vector<Element>(M, Element{}));
	}
	Puzzle(std::size_t M)
	{
		this->M = M;
		puzzle = std::vector<std::vector<Element>>(M, std::vector<Element>(M, Element{}));
	}
	Puzzle(int M, std::vector<Element> vecElement)
	{
		this->M = M;
		puzzle = std::vector<std::vector<Element>>(M, vecElement);
	}
	Puzzle(int M, int N)
	{
		this->M = M;
		puzzle = std::vector<std::vector<Element>>(M, std::vector<Element>(M, Element{}));

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				puzzle[i][j].RandomSet(N);
			}
		}

		for (int j = 0; j < M; ++j) {
			puzzle[0][j].top = 0;
			puzzle[j][0].left = 0;
			puzzle[M - 1][j].bottom = 0;
			puzzle[j][M - 1].right = 0;
		}
		for (int i = 0; i < M - 1; ++i) {
			for (int j = 0; j < M - 1; ++j) {
				puzzle[i][j].right = (-1) * puzzle[i][j + 1].left;
				puzzle[i][j].bottom = (-1) * puzzle[i + 1][j].top;
			}
		}
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				if (i > 0 && i != M - 1 && j == M - 1) {
					puzzle[i][j].top = -puzzle[i - 1][j].bottom;
				}
				if (i == M - 1 && j > 0 && j != M - 1) {
					puzzle[i][j].left = -puzzle[i][j - 1].right;
				}
			}
		}
		puzzle[M - 1][M - 1].left = -puzzle[M - 1][M - 2].right; puzzle[M - 1][M - 1].top = -puzzle[M - 2][M - 1].bottom;
	}

	// Output to the console all elements from puzzle in the format:
	// *  ft  *
	// lt     rt
	// *  bk  *
	void Print()
	{
		int max_len_x = 0;
		int max_len_y = 0;
		int max_len_z = 0;
		int max_len_w = 0;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				max_len_x = std::max(max_len_x, int(std::to_string(puzzle[i][j].right).length()));
				max_len_y = std::max(max_len_y, int(std::to_string(puzzle[i][j].top).length()));
				max_len_z = std::max(max_len_z, int(std::to_string(puzzle[i][j].left).length()));
				max_len_w = std::max(max_len_w, int(std::to_string(puzzle[i][j].bottom).length()));
			}
		}

		const int BASE_GAP_LENGHT = 6;
		int gap_lenght = BASE_GAP_LENGHT;
		int max_len_yz = std::max(max_len_x, max_len_y);
		int max_len_wx = std::max(max_len_w, max_len_x);
		if (max_len_yz >= BASE_GAP_LENGHT)
			gap_lenght = BASE_GAP_LENGHT + BASE_GAP_LENGHT * (max_len_yz / BASE_GAP_LENGHT);
		if (max_len_wx >= BASE_GAP_LENGHT - 1)
			gap_lenght = BASE_GAP_LENGHT + 2 + BASE_GAP_LENGHT * (max_len_yz / BASE_GAP_LENGHT);

		const int SPACE_LENGHT = 5;
		const char BORDER = '*';
		int curr_len;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				std::cout << BORDER;
				curr_len = int(std::to_string(puzzle[i][j].top).length());
				for (int k = 0; k < gap_lenght / 2 - curr_len / 2; k++)
					std::cout << ' ';
				std::cout << puzzle[i][j].top;
				for (int k = 0; k < gap_lenght / 2 - (curr_len - 1) / 2; k++)
					std::cout << ' ';
				std::cout << BORDER;
				for (int k = 0; k < SPACE_LENGHT; k++)
					std::cout << ' ';
			}
			std::cout << '\n';

			for (int j = 0; j < M; j++) {
				curr_len = int(std::to_string(puzzle[i][j].left).length()) + int(std::to_string(puzzle[i][j].right).length());
				std::cout << puzzle[i][j].left;
				for (int k = 0; k < gap_lenght + 3 - curr_len; k++)
					std::cout << ' ';
				std::cout << puzzle[i][j].right;
				for (int k = 0; k < SPACE_LENGHT; k++)
					std::cout << ' ';
			}
			std::cout << '\n';

			for (int j = 0; j < M; j++) {
				std::cout << BORDER;
				curr_len = int(std::to_string(puzzle[i][j].bottom).length());
				for (int k = 0; k < gap_lenght / 2 - curr_len / 2; k++)
					std::cout << ' ';
				std::cout << puzzle[i][j].bottom;
				for (int k = 0; k < gap_lenght / 2 - (curr_len - 1) / 2; k++)
					std::cout << ' ';
				std::cout << BORDER;
				for (int k = 0; k < SPACE_LENGHT; k++)
					std::cout << ' ';
			}
			std::cout << '\n';
			if (M - 1 != i) std::cout << '\n';
		}
	}
	void PrintPicture()
	{
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				PrintElementColor(i, j);
			}
			std::cout << std::endl;
		}
	}
	std::vector<Element> PuzzleToVec()
	{
		std::vector<Element> puzzle_;
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < M; ++j) {
				puzzle_.push_back(puzzle[i][j]);
			}
		}
		return puzzle_;
	}

	std::vector<Element>& operator[](std::size_t index)
	{
		return puzzle[index];
	}
};
class Picture
{
private:
	std::vector<std::vector<bool>> picture;
	std::size_t M;

	void PrintColor(int i, int j) {
		HANDLE color_out = GetStdHandle(STD_OUTPUT_HANDLE);
		if (picture[i][j]) SetConsoleTextAttribute(color_out, 0xFF);
		else SetConsoleTextAttribute(color_out, 0x88);
		std::cout << "  ";
		SetConsoleTextAttribute(color_out, 15);
	}

public:
	Picture()
	{
		this->M = 0;
		picture = std::vector<std::vector<bool>>(M, std::vector<bool>(M));
	}
	Picture(Puzzle puzzle)
	{
		this->M = puzzle.M;
		picture = std::vector<std::vector<bool>>(M, std::vector<bool>(M));
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				picture[i][j] = puzzle[i][j].color;
			}
		}
	}

	void Print()
	{
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				PrintColor(i, j);
			}
			std::cout << std::endl;
		}
	}

	std::vector<bool>& operator[](std::size_t index)
	{
		return picture[index];
	}
};
class PuzzleAssembly
{
private:
	std::vector<Element> _bytes;
	Puzzle puzzle;
	Picture picture;
	std::size_t M;
	Element voidElement{};

	void CornerAssembly()
	{
		std::size_t size_bytes = _bytes.size();

		for (int i = 0; i < size_bytes; i++) {
			// top-left angle
			if (0 == _bytes[i].top && 0 == _bytes[i].left) {
				puzzle[0][0] = _bytes[i];
				_bytes.erase(_bytes.begin() + i);
				size_bytes--;
				i--;
				continue;
			}
			// top-right angle
			if (0 == _bytes[i].top && 0 == _bytes[i].right) {
				puzzle[0][M - 1] = _bytes[i];
				_bytes.erase(_bytes.begin() + i);
				size_bytes--;
				i--;
				continue;
			}
			// bottom-left angle
			if (0 == _bytes[i].bottom && 0 == _bytes[i].left) {
				puzzle[M - 1][0] = _bytes[i];
				_bytes.erase(_bytes.begin() + i);
				size_bytes--;
				i--;
				continue;
			}
			// bottom-right angle
			if (0 == _bytes[i].bottom && 0 == _bytes[i].right) {
				puzzle[M - 1][M - 1] = _bytes[i];
				_bytes.erase(_bytes.begin() + i);
				size_bytes--;
				i--;
				continue;
			}
		}

	}

	inline bool averageAssembly(std::vector<std::vector<std::size_t>>& usedIndexElement, std::size_t& step, std::size_t& index, std::size_t& current_i, std::size_t& current_j)
	{
		/*std::cout << "---> step = " << step << '\n';*/
		bool new_element = true;
		for (std::size_t k = 0; k < usedIndexElement[step].size(); k++) {
			if (usedIndexElement[step][k] == index) {
				new_element = false;
			}
		}
		if (new_element) {
			usedIndexElement[step].push_back(index);
			puzzle[current_i][current_j] = _bytes[index];
			return false;
		}
		return true;
	}
	inline void badAssembly(std::vector<std::vector<std::size_t>>& usedIndexElement, std::size_t& step, std::size_t* iterator)
	{
		/*std::cout << "---> Bad assembly on " << step << "[" << step / M << " , " << step % M << "] . usedIndexElement count = " << usedIndexElement[step].size() << std::endl;
		std::cout << "index on usedIndexElement: ";
		for (int i = 0; i < usedIndexElement[step].size(); i++)
			std::cout << usedIndexElement[step][i] << " ";
		std::cout << std::endl;*/

		std::cout << "---> Bad assembly on " << step << " [" << step / M << " , " << step % M << "] with element " << puzzle[(step - 1) / M][(step - 1) % M].index << "\n";
		usedIndexElement[step].clear();
		step -= 2;
		*iterator = 0;
		puzzle[(step + 1) / M][(step + 1) % M] = voidElement;
	}
	inline void badAssembly_LegacyBottom(std::vector<std::vector<std::size_t>>& usedIndexElement, std::size_t& step, std::size_t* iterator)
	{
		// std::cout << "---> Bad assembly on " << step << " [" << step / M << " , " << step % M << "] with element " << puzzle[(step - 1) / M][(step - 1) % M].index << "\n";
		usedIndexElement[step].clear();
		if (M - 1 == step / M && 1 == step % M) {
			step -= 3;
		}
		else {
			step -= 2;
		}
		*iterator = 0;
		puzzle[(step + 1) / M][(step + 1) % M] = voidElement;
		//puzzle.Print();
	}
	inline void badAssembly_Bottom(std::vector<std::vector<std::size_t>>& usedIndexElement, std::size_t& step, std::vector<std::vector<std::size_t>>& matrixIterators)
	{
		/*std::cout << "---> Bad assembly on " << step << ". usedIndexElement count = " << usedIndexElement[step].size() << std::endl;
		std::cout << "index on usedIndexElement: ";
		for (int i = 0; i < usedIndexElement[step].size(); i++)
			std::cout << usedIndexElement[step][i] << " ";
		std::cout << std::endl;*/

		if (M - 1 == step / M && 1 == step % M) {
			std::cout << "---> Optimized bad assembly on " << step << " [" << step / M << " , " << step % M << "]\n";
			usedIndexElement[step].clear();
			//std::cout << "\n\n";
			//puzzle.Print();
			//std::cout << "\n\n";
			puzzle[(step) / M][(step) % M] = voidElement;
			step -= (1 + M);
			std::cout << "New step = " << step << std::endl;
			for (std::size_t i = 0; i < M - 1; i++) {
				std::cout << "iterator in " << (step + 2 + i) << std::endl;
				matrixIterators[(step + 2 + i) / M][(step + 2 + i) % M] = 0;
				puzzle[(step + 1 + i) / M][(step + 1 + i) % M] = voidElement;
			}
			for (std::size_t i = 0; i < M - 1; i++) {
				usedIndexElement[step + i + 1].clear();
			}
			/*puzzle.Print();*/
		}
		else {
			std::cout << "---> Bad assembly on " << step << " [" << step / M << " , " << step % M << "] with element " << puzzle[(step - 1) / M][(step - 1) % M].index << "\n";
			usedIndexElement[step].clear();
			step -= 2;
			matrixIterators[(step + 1) / M][(step + 1) % M] = 0;
		}
	}
	void CoreAssembly()
	{
		std::vector<std::vector<std::size_t>> matrixIterators = std::vector<std::vector<std::size_t>>(M, std::vector<std::size_t>(M));
		std::vector <std::vector<std::size_t>> used_elements{ M * M };
		std::vector<Element> _bytes_backup{};
		bool return_element = false;
		int max_step = 0;
		bool working = false;

		// fill element index
		for (std::size_t i = 0; i < _bytes.size(); i++) {
			_bytes[i].index = i;
		}
		std::vector<std::vector<std::size_t>> usedIndexElement = std::vector<std::vector<std::size_t>>(M * M);
		std::vector<Element> base_elements = _bytes;

		for (std::size_t step = 0; step < M * M; step++)
		{
			// current index on assembly puzzle matrix
			std::size_t current_j = step % M;
			std::size_t current_i = step / M;

			// parameters of the desired element
			int find_top;
			int find_left;
			bool find_color = picture[current_i][current_j];
			if (0 == current_i || 0 > current_i - 1) find_top = 0;
			else find_top = (-1) * puzzle[current_i - 1][current_j].bottom;
			if (0 == current_j || 0 > current_j - 1) find_left = 0;
			else find_left = (-1) * puzzle[current_i][current_j - 1].right;

			// find loop
			if (0 == step && working) {
				std::cout << "dead" << std::endl;
				break;
			}

			// skip corner elements
			if (0 == current_i && 0 == current_j) {
				working = true;
				continue;
			}
			if (0 == current_i && M - 1 == current_j) continue;
			if (M - 1 == current_i && 0 == current_j) continue;
			if (M - 1 == current_i && M - 1 == current_j) break;

			std::size_t* iterator = &matrixIterators[current_i][current_j];
			std::size_t size__bytes = base_elements.size();
			bool bad_assembly = true;

			// std::cout << "--> step: " << step << std::endl;

			// -------------------------------- Fill top border -------------------------------- //
			// top border with check top-right angle
			if (0 == find_top && 0 == current_i && M - 2 == current_j) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (0 == base_elements[*iterator].top && find_left == base_elements[*iterator].left && puzzle[current_i][current_j + 1].left == (-1) * base_elements[*iterator].right && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, base_elements[*iterator].index, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}
			// top border
			else if (0 == find_top && 0 == current_i) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (0 == base_elements[*iterator].top && find_left == base_elements[*iterator].left && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}

			// -------------------------------- Fill left border -------------------------------- //
			// left border with check bottom-left angle
			else if (0 == current_j && M - 2 == current_i) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (puzzle[current_i - 1][current_j].bottom == (-1) * (base_elements[*iterator].top) && find_left == base_elements[*iterator].left && puzzle[current_i + 1][current_j].top == (-1) * (base_elements[*iterator].bottom) && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}
			// left border
			else if (0 == current_j) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (puzzle[current_i - 1][current_j].bottom == (-1) * (base_elements[*iterator].top) && find_left == base_elements[*iterator].left && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}

			// -------------------------------- Fill right border -------------------------------- //
			// right border with check bottom-right angle
			else if (M - 1 == current_j && M - 2 == current_i) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (puzzle[current_i - 1][current_j].bottom == (-1) * (base_elements[*iterator].top) && find_left == base_elements[*iterator].left && 0 == base_elements[*iterator].right && puzzle[current_i + 1][current_j].top == (-1) * (base_elements[*iterator].bottom) && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}
			// right border
			else if (M - 1 == current_j) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (find_top == base_elements[*iterator].top && find_left == base_elements[*iterator].left && 0 == base_elements[*iterator].right && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}

			// -------------------------------- Fill bottom border -------------------------------- //
			// bottom border with check bottom-right angle
			else if (M - 1 == current_i && M - 2 == current_j) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (find_top == base_elements[*iterator].top && find_left == base_elements[*iterator].left && 0 == base_elements[*iterator].bottom && puzzle[M - 1][M - 1].left == (-1) * (base_elements[*iterator].right) && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}
			// bottom border
			else if (M - 1 == current_i) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (find_top == base_elements[*iterator].top && find_left == base_elements[*iterator].left && 0 == base_elements[*iterator].bottom && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					//badAssembly_Bottom(usedIndexElement, step, matrixIterators);
					badAssembly_LegacyBottom(usedIndexElement, step, iterator);
				}
			}

			// -------------------------------- Fill center -------------------------------- //
			// find element over bottom-left angle
			else if (M - 2 == current_i && 0 == current_j) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (find_top == base_elements[*iterator].top && find_left == base_elements[*iterator].left && puzzle[M - 1][0].top == (-1) * (base_elements[*iterator].bottom) && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}
			// find element over bottom-right angle
			else if (M - 2 == current_i && M - 1 == current_j) {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (find_top == base_elements[*iterator].top && find_left == base_elements[*iterator].left && puzzle[M - 1][M - 1].top == (-1) * (base_elements[*iterator].bottom) && 0 == base_elements[*iterator].right && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}
			// find other elements in center
			else {
				for (; *iterator < size__bytes; (*iterator)++) {
					if (find_top == base_elements[*iterator].top && find_left == base_elements[*iterator].left && 0 != base_elements[*iterator].right && 0 != base_elements[*iterator].bottom && find_color == base_elements[*iterator].color) {
						bad_assembly = averageAssembly(usedIndexElement, step, *iterator, current_i, current_j);
						(*iterator)++;
						break;
					}
				}
				if (bad_assembly) {
					badAssembly(usedIndexElement, step, iterator);
				}
			}

			if (max_step < step) {
				std::cout << "max assembly: " << step << " from " << M * M << " - " << double(step) / double(M * M) << "%" << std::endl;
				max_step = step;
				// puzzle.Print();
				/*std::cout << "\n";*/
			}

			/*std::cout << step << std::endl;*/
			/*if (13 == step)
			{
				std::cout << " ";
			}*/
			// puzzle.Print();
		}
	}

public:
	PuzzleAssembly(Puzzle puzzle, Picture picture, std::vector<Element> _bytes)
	{
		this->picture = picture;
		this->M = puzzle.M;
		this->puzzle = Puzzle{ M };
		this->_bytes = _bytes;
	}

	void Assembly()
	{
		CornerAssembly();
		CoreAssembly();
	}
	void PrintResult()
	{
		puzzle.Print();
		puzzle.PrintPicture();
	}
};

int main()
{
	std::string user_input;
	int N = 0;
	int M = 0;

	while (true)
	{
		std::cout << "Enter N: ";
		std::cin >> user_input;
		if (Legacy::_int(user_input, N)) {
			if (N > 0) {
				break;
			}
		}
		std::cout << "Bad input! Try again." << std::endl;
	}
	while (true)
	{
		std::cout << "Enter M: ";
		std::cin >> user_input;
		if (Legacy::_int(user_input, M)) {
			if (M > 0) {
				break;
			}
		}
		std::cout << "Bad input! Try again." << std::endl;
	}

	unsigned int seed = 0;

	//Utility::RandomN(1, seed++);
	std::cout << seed << std::endl;

	Puzzle puzzle = { M , N };
	Picture picture{ puzzle };
	puzzle.Print();
	picture.Print();

	//shuffle puzzle
	auto rng = std::default_random_engine{};
	rng.seed(0);
	std::vector<Element> _bytes = puzzle.PuzzleToVec();
	shuffle(_bytes.begin(), _bytes.end(), rng);

	// print shuffled puzzle
	Puzzle puzzle2(M);
	int index = 0;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < M; ++j) {
			puzzle2[i][j] = _bytes[index++];
		}
	}
	puzzle2.Print();
	puzzle2.PrintPicture();

	PuzzleAssembly puzzleAssembly{ puzzle, picture, _bytes };
	puzzleAssembly.Assembly();
	puzzleAssembly.PrintResult();


	//int index = 0;
	//for (int i = 0; i < M; ++i) {
	//	for (int j = 0; j < M; ++j) {
	//		puzzle2[i][j] = _bytes[index];
	//		++index;
	//	}
	//}
	//std::cout << std::endl;

	//std::cout << "\n\n\n\n";
	//puzzle_t total;
	//Assemble_Puzzle(total, void_puzzle, _bytes, p);
	//// Puzzle_Utility::Print_Puzzle(total);
	//Puzzle_Utility::Print_Picture(total);
}