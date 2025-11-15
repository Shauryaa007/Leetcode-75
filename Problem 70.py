class TrieNode:
    def __init__(self):
        self.link={}
        self.isEnd=False

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        n = len(word)
        node = self.root
        for ch in word:
            if ch not in node.link:
                node.link[ch]= TrieNode()
            node = node.link.get(ch)
        node.isEnd= True

    def search(self, word: str) -> bool:
        n = len(word)
        node = self.root
        for ch in word:
            if ch not in node.link: return False
            node = node.link.get(ch)
        return node.isEnd
        

    def startsWith(self, prefix: str) -> bool:
        n = len(prefix)
        node = self.root
        for ch in prefix:
            if ch not in node.link: return False
            node = node.link.get(ch)
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)