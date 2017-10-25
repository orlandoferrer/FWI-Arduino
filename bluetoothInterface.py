import serial
from time import sleep
import paramiko
import credentials


ser = serial.Serial('/dev/tty.barman-DevB', 9600)
ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect(server, username = username, password = password)
ftp = ssh.open_sftp()

while True:

    #file=ftp.file('ferrer.software/scale/readings.txt', "a", -1)
    file=ftp.file('ferrer.software/scale/readings.txt', "w", -1)
    #file.write(ser.readline().decode("utf-8"))
    file.write("var level = " + ser.readline().decode("utf-8"))
    file.flush()
    print(ser.readline().decode("utf-8"))
    sleep(3)

ftp.close()
ssh.close()
