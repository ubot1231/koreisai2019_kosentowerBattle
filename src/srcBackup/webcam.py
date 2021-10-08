import cv2
 
cap = cv2.VideoCapture(0)
 
width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

quitkey = 'q'
savekey = 's'

while True:
 
    ret,frame = cap.read()
 
    img = cv2.cvtColor(frame, cv2.IMREAD_COLOR)
 
    cv2.imshow('frame',img)
 

    #quit  
    if cv2.waitKey(1) & 0xFF == ord(quitkey):
        break
    # save photo to directory and quit
    if cv2.waitKey(1) & 0xFF == ord(savekey):
        path = "/Users/uboT/Desktop/opencv4Ko/img/photo.png"
        cv2.imwrite(path,frame)
        break
    
cap.release()
cv2.destroyAllWindows()