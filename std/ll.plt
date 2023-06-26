# LinkedList Implementation in Plutonium
# Written by Shahryar Ahmad 
# 7 Oct 2022
# The following code is free to use/modify and comes without any warrantee
namespace ll
{
    class Iterator
    {
        var curr = nil
        function __construct__(var addr)
        {
            self.curr = addr
        }
        function next()
        {
            self.curr = self.curr.next
        }
        function prev()
        {
            self.curr = self.curr.prev
        }
        function __noteq__(var val)
        {
            return !(self.curr is val.curr)
        }
        function __eq__(var val)
        {
            return self.curr is val.curr
        }
        function value()
        {
            return self.curr.val
        }
    }
    class Node
    {
        var val = nil
        var prev = nil
        var next = nil
    }
    class List
    {
        private var head = nil
        private var tail = nil
        function __construct__()
        {
            self.head = Node()
            self.tail = Node()
            self.head.next = self.tail
            self.head.prev = nil
            self.tail.next = nil
            self.tail.prev = self.head
        }
        function push_back(var elem)
        {
            var n = Node()
            n.val = elem
            n.prev = self.tail.prev
            self.tail.prev.next = n
            n.next = self.tail
            self.tail.prev = n
        }
        function push_front(var elem)
        {
            var n = Node()
            n.val = elem
            n.next = self.head.next
            self.head.next.prev = n
            self.head.next = n
            n.prev = self.head
        }
        function insert(var it,var elem)
        {
            if(!isInstanceOf(it,Iterator))
              throw TypeError("Iterator Object required!")
            var n = Node()
            n.val = elem
            n.prev = it.curr.prev
            it.curr.prev.next = n
            n.next = it.curr
            it.curr.prev = n
        }
        function setvalue(var it,var val)
        {
            if(!isInstanceOf(it,Iterator))
              throw TypeError("Iterator Object required!")
            it.curr.val = val
        }
        function erase(var it)
        {
            it.curr.prev.next = it.curr.next
            it.curr.next.prev = it.curr.prev
        }
        function begin()
        {
            return Iterator(self.head.next)
        }
        function end()
        {
            return Iterator(self.tail)
        }
    }

}