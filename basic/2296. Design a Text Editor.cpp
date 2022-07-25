class TextEditor {
public:
    string s;
    int pos;
    TextEditor() {
        pos=0;
    }
    
    void addText(string text) {
        
        s.insert(pos,text);
        pos+=text.size();
    }
    
    int deleteText(int k) {
            int count=0;
            while(pos!=0 && k>0){
                s.erase(pos-1,1);
                pos--;
                count++;
                k--;
                
            }
            return count; 
    }
    
    string cursorLeft(int k) {
        
        pos=pos-k<0?0:pos-k;
        string t="";
        for(int i=pos-10;i<pos;i++){
            if(i>=0)
            t+=s[i];
        }
        return t;
    }
    
    string cursorRight(int k) {
         int n=s.size();
         pos=pos+k>=n?n:pos+k;
         string t="";
         for(int i=pos-10;i<pos;i++){
             if(i>=0)
             t+=s[i];
         }
         return t; 
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
