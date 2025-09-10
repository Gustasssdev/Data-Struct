class Node:
    def __init__(self, data):
        self.data = data
        self.next = None




class LinkedList:
    def __init__(self):
        self.head = None


    def add(self, elemento):
        novo = Node(elemento) #adiciona um elemento no inicio da lista
        novo.next = self.head
        self.head = novo


    def add_end(self, elemento): #adiciona um elemento no final da lista
        new = Node(elemento)
        if self.head is None:
            self.head = new
            return

        atual = self.head # pega o no atual e recebe a cabeça do nó para colocar no final da lista 
        while atual.next is not None:
            atual = atual.next
        atual.next = new


    def mostrar(self):
        seqFrutas = ""
        aux = self.head
        while aux is not None:
            seqFrutas += f"{aux.data} - "
            aux = aux.next
        return seqFrutas
   
    def size(self):
        count = 0
        aux = self.head
        while aux is not None:
            count += 1
            aux = aux.next
        return count
       
    
    def search(self, item):
        var_busca = self.head
        while var_busca is not None:
            if var_busca.data == item:
                return True
            var_busca = var_busca.next
        return False        


    # fazer uma função que busca um item em uma lista encadeada
    # fazer uma função que remove no começo e no final 
    # fazer uma função que remove um valor que o usuario passar 
    #        
















l = LinkedList()


l.add("papaya")
l.add("pera")
l.add("maca")
l.add_end("abacate")
l.add("bola de golfe")


print(l.mostrar())
print(l.size())
print(l.search("abacate"))


