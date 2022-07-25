class FoodRatings {
public:
 
    map<string,set<pair<int,string>>>rating;
    unordered_map<string,string>dish;
    unordered_map<string,int>mp;
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
           
          for(int i=0;i<f.size();i++){
              
              dish[f[i]]=c[i];
              rating[c[i]].insert({-r[i],f[i]});
              mp[f[i]]=-r[i];
          }    
    }
    
    void changeRating(string food, int newRating) {
        
        string cuisineType=dish[food];
        rating[cuisineType].erase({mp[food],food});
        rating[cuisineType].insert({-newRating,food});
        mp[food]=-newRating;
        
    }
    string highestRated(string cuisine) {
     
       
             pair<int,string>p=*(rating[cuisine].begin());
             return p.second;
            
           
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
