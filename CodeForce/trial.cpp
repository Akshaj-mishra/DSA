if (intervals[i][1] < intervals[i-1][1]){
    inter.push_back(intervals[i-1][1]);
}else{
    inter.push_back(intervals[i][1]);
}