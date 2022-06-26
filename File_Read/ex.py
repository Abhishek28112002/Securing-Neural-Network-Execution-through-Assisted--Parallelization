# networknum=int(input('enter the network number(1-resnet18,2-alexnet,3-vgg16,4-squeezenet1_0,5-googlenet,6-mobilenet_v2)'))
# frequency_l_core= int(input('frequency of Little core?(1-200Hz,2-600Hz,3-1000Hz,4-1400Hz)'))
# frequency_b_core= int(input('frequency of Big core?(1-800Hz,2-1200Hz,3-1600Hz,4-2000Hz)'))
import csv 
for networknum in range(1,7):
    for frequency_l_core in range(1,5):
        for frequency_b_core in range(1,5):
            if frequency_l_core==3 and frequency_b_core==1:
                continue
            if frequency_l_core==4 and frequency_b_core==1 or frequency_b_core==2:
                continue
            nnetwork= networknum*4 -5
            line_number_lcore= nnetwork + frequency_l_core
            line_number_bcore= nnetwork + frequency_b_core + 6*4 
#print(nnetwork,line_number_lcore, line_number_bcore)

            with open("./File_Read/nn_layerruntimes.csv","r") as file:
                data = file.readlines()
                file.close()

            data_l= data[line_number_lcore].split(',')
            nlayers=int(data_l[3])
            thgc = [None] * nlayers
            for i in range(0,nlayers):
                thgc[i]=int(data_l[i+4])

            data_h= data[line_number_bcore].split(',')
            tpc = [None] * nlayers
            for i in range(0,nlayers):
                tpc[i]=int(data_h[i+4])
            # print(nlayers,thgc,tpc)

            with open("./File_Read/network_shapes.csv","r") as file:
                data = file.readlines()
            file.close()

            data_comm= data[networknum-1].split(',')
            #print (data_comm)

            with open("./File_Read/socket_times.csv","r") as file:
                data= file.readlines()
            file.close()

            lno= nnetwork + frequency_b_core + 2

            comm=data[lno].split(',')
            #print(comm)

            tcomm = [None] * nlayers

            for i in range(0,nlayers):
                num=4*1024
                c=2
                while (1<2):
                    if(int(data_comm[i+2])<num):
                        tcomm[i]=comm[c]
                        #print(data_comm[i+2], num, comm[c])
                        break
                    else:
                        num= num*2
                        c=c+1
            network_name=str(data_l[0])
            lower_frequencies=str(data_l[2])
            higher_frequencies=str(data_h[2])
            name=network_name+'_'+lower_frequencies+'_'+higher_frequencies
            filename="%s.txt" % name
            print(filename)
            with open('input/Result.csv','a') as f:
               writer=csv.writer(f)
               writer.writerow(str(network_name))
            f.close()
            with open('input/'+filename, 'w') as f:
                f.write(str(nlayers) + ' ')
                for i in tpc:
                    f.write(str(i)+ ' ')
                f.write("\n")
                f.write(str(nlayers)+ ' ')
                for i in thgc:
                    f.write(str(i)+ ' ')
                f.write("\n")
                f.write(str(nlayers)+ ' ')
                for i in tcomm:
                    f.write(str(i)+ ' ')
                f.write("\n")
            f.close()
            



                
