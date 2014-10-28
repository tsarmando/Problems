#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

bool wordRight(char v[], vector<char> b)
{
	//assume word b is sorted
	set <char> a (v, v + strlen(v));
	vector <char> intersect(a.size() + b.size());
	vector <char>::iterator it;
	unsigned size = a.size() > b.size() ? b.size() : a.size();

	it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), intersect.begin());
	intersect.resize(it-intersect.begin());

	if(intersect.size() == size)
		return true;
	return false;
}

int readWordsFromFile(char words[100000][32], const char file[])
{
    int i = 0;
    FILE *fp = fopen(file, "r");
    
    while(1)
    {
        fscanf(fp, "%s", words[i++]);       
        if(feof(fp))  break;
    }
    fclose(fp);
    return i;
}

int main(){
	static char words[100000][32];
	FILE *p = fopen("Left Hand Words.txt", "w");
	int  nWords = readWordsFromFile(words, "wordlist.txt");
	char right[] = {'y' , 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'b', 'm', 'n'};
	char left[] = {'q','w','e','r','t','a','s','d','f','g','z','x','c','v'};
	vector<char> Right (right, right + sizeof(right));
	vector<char> Left (left, left + sizeof(left));
	sort(Right.begin(), Right.end());
	sort(Left.begin(), Left.end());
	int j = 0;
	for(int i = 0; i < nWords; i++){

		if(wordRight(words[i], Left)){
			j++;
			fprintf(p, "%s\t", words[i]);
			if(j% 5== 0)
				fprintf(p, "\n");
		}
	}

}
