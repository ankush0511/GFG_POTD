
int count=1;
int maxheight=height[0];
for(int i=0; i<height.size(); i++) {
    if(maxheight<height[i]) {
        count++;
        maxheight=height[i];
    }
}
return count;
