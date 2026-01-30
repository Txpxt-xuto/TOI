import matplotlib.pyplot as plt
x1 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
y1 = [0.0,0.0,0.0,0.0,0.5,1.6,2.2,2.7,3.1,3.5,3.9,4.0,4.4,4.6,4.9,5.0,5.3,5.6,6.0,6.6,6.9,7.0,7.6,8.3,8.4,8.5,8.5,8.6,9.1,9.4]
x2 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
y2 = [0.0,0.0,0.0,0.0,0.5,0.8,1.2,1.6,1.9,2.2,2.6,2.9,3.2,3.6,3.7,4.0,4.5,5.0,5.0,5.6,5.8,6.2,6.4,6.7,6.9,7.4,8.0,8.2,8.2,8.3]
x3 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
y3 = [0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.4,0.5,0.9,1.2,1.4,2.3,3.2,4.1,4.9,5.7,5.8,6.1,6.8,7.1,7.2,7.3,7.5,7.6,7.9,8.0,8.6,8.9]
plt.plot(x1,y1,label='Animal manure')  #ระบุ label สำหรับ legend ได้
plt.plot(x2,y2,label='Microbial fertilizer') # plot กราฟ series ที่สอง
plt.plot(x3,y3,label='Composted leaf fertilizer') # plot กราฟ series ที่สอง
plt.xlabel('Time (day)') #ชื่อแกน x
plt.ylabel('Hight (cm)') #ชื่อแกน y
plt.title('The graph shows the relationship between the height of sunflower seedlings\nfrom each type of fertilizer and the time spent in the experiment.') #ชื่อกราฟ ขึ้นบรรทัดใหม่ได้ด้วย \n
plt.legend()  #แสดง Legend
plt.show()  #บรรทัดนี้ใน colab ใส่ก็ได้ ไม่ใส่ก็ได้