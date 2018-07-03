import QtQuick 2.9
import QtQuick.Controls 1.4

Rectangle {
    id: uitag
    height: 70
    width: 200
    color: "transparent"
    border.color: "black"
    border.width: 2
    radius: 2
    signal update
    property var xx
    property var yy
    property int i
    property var hl
    property var wl
    Row{
        x:5
        width: parent.width
        anchors.verticalCenter: uitag.verticalCenter
        Rectangle{
            width: 5
            height: parent.height
            color: "light green"
        }
        Column{
            width:65
            Text{
                text:'X: '+ uitag.xx
                color:'black'
                font.pointSize: 17
            }
            Text{
                text:'Y: '+ uitag.yy
                color:'black'
                font.pointSize: 17
            }
        }
        Column{
            width: 70
            TextField {
                id:newx
                focus: true
                validator: IntValidator { bottom:0; top: wl}
            }
            TextField {
                id:newy
                focus: true
                validator: IntValidator { bottom:0; top: hl}
            }
        }
        Rectangle{
            width: 5
            height: parent.height
            color: "light green"
        }
        Button{
            id: sb
            width: 35
            height: parent.height
            text: "Set\n"+i
            onClicked: {
                uitag.update()
                xx = newx.displayText
                yy = newy.displayText
               // newx.remove(0,newx.length)
               // newy.remove(0,newx.length)
            }
        }
    }
}
