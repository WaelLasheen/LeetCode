class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> s;
        for(char i:brokenLetters){
            s.insert(i);
        }

        int rem=0 ,words=1;
        for(int i=0;i<text.size();i++){
            if(s.count(text[i])){
                rem++;
                while(i<text.size() && text[i] !=' '){
                    i++;
                }
            }
            if(text[i]==' '){
                words++;
            }
        }

        return words-rem;
    }
};