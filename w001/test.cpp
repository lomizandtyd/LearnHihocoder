#include <iostream>
#include <string>

int maximum_length_of_symmetry(std::string& s) {
    if (s.empty())
        return 0;
        
    int end = s.length();
    int maximum_length = 1;
    
    for (int begin=0; begin<end; ++begin) {
        int begin_half_length = 1;

        // odd
        int left = begin - begin_half_length;
        int right = begin + begin_half_length;
        while (left>=0 && right <end && s[left] == s[right]) {
            begin_half_length += 1;
            left -= 1;
            right += 1; 
        }
        int odd_length =  2 * begin_half_length - 1;

        // even
        begin_half_length = 0;
        left = begin - begin_half_length;
        right = begin + 1 + begin_half_length ;

        while (left>=0 && right <end && s[left] == s[right]) {
            begin_half_length += 1;
            left -= 1;
            right += 1; 
        }

        int even_length = 1;
        if (begin_half_length > 0) 
            even_length = 2 * (begin_half_length-1);

        if (even_length > maximum_length)
            maximum_length = even_length;

        if (odd_length > maximum_length)
            maximum_length = odd_length;
    }
    return maximum_length;
}


int main(int argc, char* argv[]) {
    int n=0;
    std::cin >> n;
    std::string s;
    for (; n>0; n--) {
        std::cin >> s;
        std::cout << maximum_length_of_symmetry(s) << std::endl;
    }
    return 1; 
}
