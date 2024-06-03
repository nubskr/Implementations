bool check(int k){
     bool ret = 1;
     // checker here
     return ret;
}
/*
this implementation assumes the function increases continuously and then decreases continuously

it finds the peak

modify it for your applications
*/
int l = -1, r = n;
while (r - l > 1){
     int mid =  l + (r - l)/2;
     if (check(mid) > check(mid + 1)){
          r = mid;
     }
     else{ 
          l = mid;
     }
}
//l + 1 is the answer