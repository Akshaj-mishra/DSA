class Solution {
public:
    int strStr(string haystack, string needle) {
    //     if (haystack == needle){
    //         return 0;
    //     }
    //     int l = 0;
    //     int r = needle.size()-1;
    //     int n = haystack.size()-1;
    //     bool val = false;
    //     while (r < n){

    //         if (haystack[l] == needle[0]){
    //             string str = "";
    //             for (int i = l; i <=r; i++){
    //                 str += haystack[i];
    //             }
    //             if (str == needle){
    //                 val = true;
    //                 break;
    //             }
    //         }
            
    //         l++;
    //         r++;
            
            
    //     }
    //     if (val){
    //         return l;
    //     }
    //    return -1;


    int i = haystack.find(needle);
    if (i != haystack.npos){
        return i;
    }
    return -1;
    }
};