#include <iostream>
#include <vector>

void rec(std::vector<std::string> &result, std::string str, int j, int n, int temp1, int temp2) {
    if (j == n) {
        result.push_back(str);
    } else {
        int t1 = 0, t2 = 0, i, fl = 1;
        for(i = j - 1; fl && i >= 0; --i) {
            switch (str[i]) {
                case '(': --t1; break;
                case '[': --t2; break;
                case ')': ++t1; break;
                case ']': ++t2; break;
                default: break;
            }
            if( t1 < 0 || t2 < 0) fl = 0;
        }
        if (fl) {
            str[j] = '(';
            rec(result, str, j + 1, n, temp1 + 1, temp2);
            str[j] = '[';
            rec(result, str, j + 1, n, temp1, temp2 + 1);
        } else {
            if (t1 < 0) {
                str[j] = ')';
                rec(result, str, j + 1, n, temp1, temp2);
                if(temp1 + temp2 < n / 2) {
                    str[j] = '(';
                    rec(result, str, j + 1, n, temp1 + 1, temp2);
                    str[j] = '[';
                    rec(result, str, j + 1, n, temp1, temp2 + 1);
                }
            }
            if (t2 < 0) {
                str[j] = ']';
                rec(result, str, j + 1, n, temp1, temp2);
                if (temp1 + temp2 < n / 2) {
                    str[j] = '(';
                    rec(result, str, j + 1, n, temp1 + 1, temp2);
                    str[j] = '[';
                    rec(result, str, j + 1, n, temp1, temp2 + 1);
                }
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    if (n % 2 != 0) {
        return 0;
    }

    std::string str(n, '0');
    std::vector<std::string> result;

    str[0] = '(';
    rec(result, str, 1, n, 1, 0);

    str[0] = '[';
    rec(result, str, 1, n, 0, 1);

    std::sort(result.begin(), result.end());

    for (auto i: result) {
        std::cout << i << std::endl;
    }

    return 0;
}