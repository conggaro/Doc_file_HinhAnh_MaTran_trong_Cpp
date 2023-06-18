// Yêu cầu:
// 1. đọc file
// 2. tìm điểm ảnh tối nhất
// 3. tìm điểm ảnh sáng nhất
// 4. đếm số điểm ảnh nhỏ hơn 70

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// tạo hàm chuyển 1 chuỗi thành các số 
// rồi bỏ vào trong vector
vector<int> Ham_Chuyen_String_Thanh_Vector(string str, vector<int> &item){
    // tạo bộ nhớ tạm thời
    string data = "";
    
    for (int i = 0; i < str.length(); i++)
    {
        // khi gặp cái ký tự cách
        // thì sẽ nhận biết được 1 số
        if (str[i] == ' ')
        {
            int x = stoi(data);
            item.push_back(x);

            // sau khi push xong thì xóa dữ liệu bên trong data
            data = "";
        }

        data = data + str[i];

        // trường hợp 2:
        // khi đọc đến cuối cái str thì không có dấu cách
        // thì i == str.length() - 1
        // sẽ nhận biết số cuối cùng
        if (i == str.length() - 1)
        {
            int x = stoi(data);
            item.push_back(x);
        }
    }

    return item;
}

int main(){
    // tạo vector để hứng dữ liệu
    vector<string> v;

    // tạo item để hứng cả 1 dòng dữ liệu
    string item = "";

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("anh.dat", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file anh.dat THAT BAI\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file anh.dat THANH CONG\n\n";

        while (file_in.eof() == false)
        {
            if (file_in.eof() == true)
            {
                break;
            }
            
            // ghi dữ liệu vào cái item
            getline(file_in, item, '\n');
            
            // thêm cái item vào v
            // sau khi item đã được ghi xong
            v.push_back(item);
        }

        file_in.close();
    }

    // tạo 1 cái vector 2 chiều để xử lý dữ liệu
    vector<vector<int>> v2(0, vector<int>(0, 0));


    // bây giờ phải chuyển từng dòng string của "vector v"
    // vào từng cái vector item
    // mỗi 1 cái vector item thì nó sẽ lưu 1 dãy số của 1 dòng string
    for (int i = 0; i < v.size(); i++)
    {
        // tạo vector item
        vector<int> v_item(0);

        Ham_Chuyen_String_Thanh_Vector(v[i], v_item);
        
        // đây là cái việc làm push vector<int> vào trong v2
        v2.push_back(v_item);
    }
    
    // làm xong thì chúng ta thu được vector v2 như này
    for (int i = 0; i < v2.size(); i++)
    {
        for (int j = 0; j < v2[i].size(); j++)
        {
            cout << v2[i][j] << "\t";
        }
        cout << "\n\n";
    }

    return 0;
}