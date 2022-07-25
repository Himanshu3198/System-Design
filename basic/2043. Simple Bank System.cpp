class Bank {
public:
    
      vector<long long>nums;
    Bank(vector<long long>& balance) {
        
        for(auto it:balance){
            
            nums.push_back(it);
        }
    }
    
    bool transfer(int ac1, int ac2, long long money) {
        int n=nums.size();
        
        if(ac1<1 or ac1>n or ac2<1 or ac2>n) return false;
         ac1--;
          ac2--;
        if(money>nums[ac1]) return false;
         
        nums[ac1]-=money;
        nums[ac2]+=money;
        return true;
    }
    
    bool deposit(int ac, long long money) {
         int n=nums.size();
        
        if(ac<1 or ac>n) return false;
         
        ac--;
        nums[ac]+=money;
        
        return true;
          
    }
    
    bool withdraw(int ac, long long money) {
         int n=nums.size();
        if(ac<1 or ac>n) return false;
        
        ac--;
        
        if(money>nums[ac]) return false;
        nums[ac]-=money;
        
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
