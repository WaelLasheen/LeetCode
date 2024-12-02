class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int l,r,it;
        l=r=it=0;
        int len = searchWord.size() ,ord=0;
        sentence +=" "; // our solution not take last word so we add space to take it

        while(r<sentence.size()){
            if(sentence[r]==' '){
                ord++;     // current order of word in sentence
                if( r-l >= len){
                    while(l<r){
                        if(searchWord[it]== sentence[l]){
                            l++;
                            it++;
                            if(it== len){
                                return ord;
                            }
                        }
                        else{
                            it=0;
                            l=r+1;
                            break;
                        }
                    }
                }
                else{
                    l=r+1;
                }
            }
            r++;
        }

        return -1;
    }
};