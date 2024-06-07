class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        words_list = sentence.split(" ")  
        dictionary.sort(key=len)
        for i in range(len(words_list)):
            for root in dictionary:
                if words_list[i].startswith(root):
                    words_list[i] = root
                    break  
        result = " ".join(words_list)
        return result 