import matplotlib.pyplot as plt

x1 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
y1 = [0.0,0.0,0.0,0.0,0.9,1.3,1.9,2.6,3.1,3.6,4.0,4.6,5.0,6.1,6.4,7.0,7.0,7.2,7.6,7.9,8.3,8.4,8.9,9.2,9.5,9.7,10.1,10.6,11.4,12.1]

x2 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
y2 = [0.0,0.0,0.0,0.0,0.1,0.1,0.1,0.4,0.9,1.2,1.4,1.6,1.7,1.8,2.1,2.3,2.6,3.5,4.0,4.6,4.9,5.4,6.0,7.1,7.8,9.3,9.5,10.1,10.4,10.5]

x3 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
y3 = [0.0,0.0,0.0,0.0,0.3,0.7,0.8,0.9,1.0,1.1,1.3,1.4,1.6,1.7,2.8,3.3,4.0,5.2,5.5,5.6,5.9,6.4,6.6,7.0,7.1,7.3,7.6,8.4,9.6,11.1]

plt.plot(x1,y1,label='Animal manure')  #ระบุ label สำหรับ legend ได้
plt.plot(x2,y2,label='Microbial fertilizer') # plot กราฟ series ที่สอง
plt.plot(x3,y3,label='Composted leaf fertilizer') # plot กราฟ series ที่สอง
plt.xlabel('Time (day)') #ชื่อแกน x
plt.ylabel('Hight (cm)') #ชื่อแกน y
plt.title('The graph shows the relationship between the height of coriander plants\nfrom each type of fertilizer and the time spent in the experiment.') #ชื่อกราฟ ขึ้นบรรทัดใหม่ได้ด้วย \n
plt.legend()  #แสดง Legend
plt.show()  #บรรทัดนี้ใน colab ใส่ก็ได้ ไม่ใส่ก็ได้