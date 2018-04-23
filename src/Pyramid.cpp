#include <vector>
#include <iostream>
#include <string>



int main(int argc, char** argv){

  if(std::stoi(argv[argc-1]) != 0){
    std::cout << "end with 0 " << std::endl;
    return 0;
  }





  for (int f = 1; f < argc-1; f++){
    std::vector<int> val, weight, ans;
    std::vector<std::string> output;
    int size = 5;
    int W = std::stoi(argv[f]);

    weight.push_back(5);
    weight.push_back(10);
    weight.push_back(14);
    weight.push_back(20);
    weight.push_back(30);

    val.push_back(5);
    val.push_back(10);
    val.push_back(14);
    val.push_back(20);
    val.push_back(30);

    output.push_back("2h");
    output.push_back("3l");
    output.push_back("3h");
    output.push_back("4l");
    output.push_back("4h");


    int n = size;
    int min_blocks[n+1][W+1];
    int pyramid[n+1][W+1];




 
    for (int i=0; i<=W; i++){
      min_blocks[0][i] = 0;
      pyramid[0][i]=0;
    }

    for (int i=1; i<=n; i++){
      min_blocks[i][0] = 0;
      pyramid[i][0]=0;
    }


    for (int i=1; i<=n; i++){
      for (int j=1; j<=W; j++){
        if (weight[i-1] > j){
          min_blocks[i][j] = min_blocks[i-1][j];
          pyramid[i][j] = pyramid[i-1][j];
        }
	else{
          if(weight[i-1] + pyramid[i-1][j] > j && val[i-1] > min_blocks[i-1][j]){
           min_blocks[i][j] = val[i-1];
           pyramid[i][j] = weight[i-1];
         }
	else{
           if(min_blocks[i-1][j] > min_blocks[i][j-1] + val[i-1]){
            min_blocks[i][j] = min_blocks[i-1][j];
            pyramid[i][j] = pyramid[i-1][j];
          }
          else{
            if(weight[i-1] + pyramid[i-1][j] <= W){
             min_blocks[i][j] = min_blocks[i-1][j-1] + val[i-1];
             pyramid[i][j] = pyramid[i-1][j-1] + weight[i-1];
           }else{
             if(val[i-1]+min_blocks[i-1][j-1]>min_blocks[i-1][j] && weight[i-1]+pyramid[i-1][j-1] <= W){
              min_blocks[i][j] = val[i-1] + min_blocks[i-1][j-1];
              pyramid[i][j] =  weight[i-1] + pyramid[i-1][j-1];
            }else{
              min_blocks[i][j] = min_blocks[i][j-1];
              pyramid[i][j] = pyramid[i][j-1];
            }
          }
        }
      }
    }


  }

}




if(min_blocks[5][W-1] != W){

  std::cout << "Case " << f << ": inconceivable!" << std::endl;
}
else{

  int bottom = 0;
  int top = 0;
  for (int i = 0; i < W; i++){
    if(pyramid[size-1][i] != top){
      for (int j = 0; j < size; j++)
      {
        if(val[j] == pyramid[size-1][i]){
          ans.clear();
          top = val[j];
          ans.push_back(val[j]);
        }
        else if(top+val[j] == pyramid[size-1][i]){
          top = top+val[j];
          ans.push_back(val[j]);

        }
      }
    }
    bottom = pyramid[size-1][i];

  }
std::cout << "Case " << f << " ";


  for (int i = 0; i < ans.size(); i++){
    for(int j = 0; j<size; j++){
      if(val[j] == ans[i]){
        std::cout << output[j] << " ";
      }

    }
  }
  std::cout << std::endl;
}


}




}
