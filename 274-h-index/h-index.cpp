class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(),citations.rend());
        int res=0 ,s=citations.size();
        for(int i=0;i<s;i++){
            if(citations[i] >= i+1) res++;
        }
        return res;
    }
};

/*
for understand it well see these examples with explation

Example 1:
Input: citations = [3, 0, 6, 1, 5]

Let's break this down step-by-step:

Citation Counts:

The researcher has 5 papers.
The citations for these papers are: 3, 0, 6, 1, and 5.
Sorting the Citation Array:

Sort the citations in descending order: [6, 5, 3, 1, 0].
Determine h-index:

Start from the highest citation count and work your way down.

The h-index is the largest number h such that the researcher has h papers with at least h citations.

First Paper: 6 citations (at least 1 paper with at least 1 citation)

Second Paper: 5 citations (at least 2 papers with at least 2 citations)

Third Paper: 3 citations (at least 3 papers with at least 3 citations)

Fourth Paper: 1 citation (at least 4 papers with at least 4 citations — not true)

Fifth Paper: 0 citations (at least 5 papers with at least 5 citations — not true)

Thus, the h-index is 3 because there are 3 papers with at least 3 citations each.

Example 2:
Input: citations = [1, 3, 1]

Let's break this down step-by-step:

Citation Counts:

The researcher has 3 papers.
The citations for these papers are: 1, 3, and 1.
Sorting the Citation Array:

Sort the citations in descending order: [3, 1, 1].
Determine h-index:

Start from the highest citation count and work your way down.

The h-index is the largest number h such that the researcher has h papers with at least h citations.

First Paper: 3 citations (at least 1 paper with at least 1 citation)

Second Paper: 1 citation (at least 2 papers with at least 2 citations — not true)

Third Paper: 1 citation (at least 3 papers with at least 3 citations — not true)

Thus, the h-index is 1 because there is only 1 paper with at least 1 citation.
*/