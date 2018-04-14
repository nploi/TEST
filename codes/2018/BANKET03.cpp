/*
 * Sensor được sử dụng phổ biến để ghi nhận các thông số môi trường trong cuộc sống hằng ngày.
 Sensor thường xuyên ghi nhận các thông số và định kỳ sẽ gửi về trung tâm. Để tiết kiệm lượng 
dữ liệu cần gửi, sensor sẽ nén dữ liệu trước khi gửi. Nhóm nghiên cứu của bạn đề xuất cách nén
 một dãy gồm N số nguyên dương tăng dần theo quy tắc biểu diễn dãy các số có giá trị liên tục 
tăng dần thành một đoạn theo nguyên tắc sau:

• Nếu dãy chỉ gồm 1 phần tử thì chỉ ghi phần tử này.

• Gọi 2 số đầu và cuối của dãy là X và Y

• Nếu X và Y có số lượng chữ số khác nhau thì nén dãy lại thành “X-Y” (không có dấu ngoặc kép)

• Nếu X và Y có số lượng chữ số bằng nhau, ta xét X,Y như 2 chuỗi kí tự, gọi i là giá trị lớn
 nhất mà X[1..i] = Y[1..i]. Trong trường hợp này ta nén dãy lại thành 
“X-Y[i+1..len(Y)]” (không có dấu ngoặc kép). Trong đó X[i..j] là xâu con 
từ vị trí thứ i đến vị trí thứ j của X (đánh số từ 1), len(X) là độ dài của xâu X,
 trường hợp i > j thì X[i..j] là xâu rỗng.

Ví dụ:

    Dãy số 98, 99, 100, 101 được viết thành 98-101

    Dãy số 10, 11, 12, 13, 14, 15 được viết thành 10-5 (không phải là 10-15).

    Dãy số 119, 120, 121 được viết thành 119-21 (không phải là 119-121).

Cho trước một dãy số gồm N số nguyên dương, hãy biểu diễn thông tin của dãy số này sau khi
 nén sao cho số đoạn là ít nhất có thể và dãy số được nén phải giữ nguyên thứ tự so với dãy chưa nén.

Input Format

Dòng đầu tiên là một số nguyên dương N <= 10^4 cho biết số lượng phần tử trong dãy số. 
N dòng còn lại là N số nguyên dương có giá trị tối đa là 10^5.

Constraints

N <= 10^4

Các số nguyên dương có giá trị tối đa là 10^5

Output Format

Các đoạn giá trị sau khi nén dãy số, mỗi đoạn giá trị ghi trên một dòng.

Sample Input 0

9
8
10
11
12
13
98
99
100
101

Sample Output 0

8
10-3
98-101


 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
template <typename T>
std::string genericToString(const T& t)
{
    std::ostringstream oss;
    oss << t;
    return oss.str();
}


int main() {
    int n;
    cin >> n;
    vector<long long> v;
    while(n--){
        long long num;
        cin >> num;
        v.push_back(num);
    }

    long s = v[0], e;
    for (int i = 1; i < v.size(); ++i) {
        if(v[i] - v[i - 1] != 1 || (i == v.size() - 1)){
            e = v[i - 1];
            if(e == s){
                cout << s << endl;
            }else {
                string s1 = genericToString(s);
                string s2 = genericToString(e);
                if (s1.size() == s2.size() || i == v.size() - 1) {
                    int j = 0;
                    for (int i = 0; i < s1.size(); ++i) {
                        if(s1[i] == s2[i]){
                            j++;
                        }
                    }
                    if(j == 0){
                        cout << s << "-" << e << endl;
                    }else{
                        cout << s << "-" << s2.substr(j, s2.size()) << endl;
                    }
                }


            }
            s = v[i];
        }

    }


    return 0;
}
