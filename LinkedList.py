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
            seqFrutas += f"{aux.data} -> "
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

    def remove_ini(self):
        aux = self.head
        self.head = aux.next
        aux = None
        return

    def remove_fim(self):
        if self.head is None:
            print("Lista vazia!")
            return

        if self.head.next is None:  # só 1 elemento
            self.head = None
            return

        atual = self.head
        while atual.next.next is not None:  # vai até o penúltimo
            atual = atual.next

        atual.next = None  # remove o último
      
    def remove_item(self,item):
        busca = self.head
        while busca.next is not None:
            if busca.next.data == item:   # achou no próximo nó
                busca.next = busca.next.next  # remove a ligação
                return
            busca = busca.next

        return "O elemento não existe na lista"





l = LinkedList()


l.add("papaya")
l.add("pera")
l.add("maca")
l.add_end("abacate")
l.add("bola de golfe")


print(l.mostrar())
print(l.size())
print(l.search("abacate"))
print("")
#l.remove_ini()
print(l.mostrar())
#l.remove_fim()
print(l.mostrar())
l.add("uva")
l.add("abobora")
l.remove_item("papaya")
print(l.mostrar())
