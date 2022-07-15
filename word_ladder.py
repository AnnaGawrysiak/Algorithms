# A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of
# words beginWord -> s1 -> s2 -> ... -> sk such that:
#
# Every adjacent pair of words differs by a single letter.
# Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
# sk == endWord
# Given two words, beginWord and endWord, and a dictionary wordList, return the number of words
# in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.


from queue import Queue

def find_words_that_differ_by_one_letter_only(expression, word_list):

    words = []

    for word in word_list:
        diff = 0
        for i in range(len(word)):
            if word[i] != expression[i]:
                diff +=1
        if diff == 1:
            words.append(word)

    return words

def transformation(begin_word, end_word, word_list):

    if end_word not in word_list:
        return 0

    graph = {}

    if begin_word not in word_list:
        word_list.append(begin_word)

    for word in word_list:
        neighbours = find_words_that_differ_by_one_letter_only(word, word_list)
        graph[word] = neighbours

    steps = bfs(begin_word, end_word, word_list, graph)
    return steps

def bfs(begin_word, end_word, word_list, graph):
    parent = dict()
    parent[begin_word] = None

    visited = []
    q = Queue()
    q.put(begin_word)

    path_found = False

    while q:
        node = q.get()
        visited.append(node)

        if node == end_word:
            path_found = True
            print("Target found")
            break

        adjacent = graph[node]

        for a in adjacent:
            if a not in visited:
                parent[a] = node
                q.put(a)

    path = []

    if path_found:
        path.append(end_word)
        while parent[end_word] is not None:
            path.append(parent[end_word])
            end_word = parent[end_word]
        path.reverse()
    return path


# Press the green button in the gutter to run the script.
if __name__ == '__main__':

    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot", "dot", "dog", "lot", "log", "cog"]

    path = transformation(beginWord, endWord, wordList)
    print(path)
    print(f"How many steps? : {len(path)-1} ")