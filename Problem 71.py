class Trie:
    def __init__(self):
        self.sub = {}
        self.suggestion = []
class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        root = Trie()
        for product in sorted(products):
            self._insert(product, root)
        return self._search(searchWord, root)    
    def _insert(self, product: str, root: Trie) -> None:
        trie = root
        for char in product:
            if char not in trie.sub:
                trie.sub[char] = Trie()
            trie = trie.sub[char]
            trie.suggestion.append(product)
            trie.suggestion.sort()
            if len(trie.suggestion) > 3:
                trie.suggestion.pop()
    def _search(self, searchWord: str, root: Trie) -> List[List[str]]:              
        ans = []
        for char in searchWord:
            if root:
                root = root.sub.get(char)
            ans.append(root.suggestion if root else [])            
        return ans