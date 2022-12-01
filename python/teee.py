import turtle as t
import random

t.pensize(3)
t.speed(0)
  
color_list=['red','orange','yellow','blue','navy','purple']

count = 0

def drawit(x,y):
    global count
    t.color(random.choice(color_list))
    t.penup()
    size=random.randint(10,50)  
    t.goto(x,y)
    t.pendown()
    t.begin_fill()
    t.circle(size)
    t.end_fill()
    count += 1
    if count == 5:
        exit()

t.onscreenclick(drawit)
t.listen()
t.mainloop()