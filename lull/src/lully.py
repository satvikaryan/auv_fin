import rospy    
from std_msgs.msg import String

user = ""

def messageCallback(msg):
    if (msg.data.startswith("["+ user + "]")):
        return
    print("\n[%s] Received message: %s\n" % (user, msg.data))

def sendMessage(message):
    msg = String()
    msg.data = "[" + user + "] " + message
    pub.publish(msg)

user = str(input("Enter your username: "))
chat_topic = str(input("Enter your topic: "))

rospy.init_node(user)
pub = rospy.Publisher(chat_topic, String, queue_size=1000)
rospy.Subscriber(chat_topic, String, messageCallback)

rate = rospy.Rate(10)

while not rospy.is_shutdown():
    message = str(input("[%s] Enter your message: " % user))
    sendMessage(message)

ros.spin_once()
rate.sleep()