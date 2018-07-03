import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import Mymap 1.0
Rectangle{
    id:drawarea
    property MapElements mapread
    color:"red"
    x:100
    width: parent.width-100
    height: parent.height
    Repeater{
        model: mapread.lenofTrack
        Item{
            Text {
                x:mapread.getTstartx(index)
                y:mapread.getTstarty(index)
                text: '>'+index
            }
            Text {
                x:mapread.getTendx(index)
                y:mapread.getTendy(index)
                text: index+'>'
            }
        }
    }
    Repeater{
        model: mapread.lenofAGV
        Item{
            Text {
                x:mapread.getAx(index)
                y:mapread.getAy(index)
                text: '['+index+']'
            }
            AGVmarker{
                x:mapread.getAx(index);
                y:mapread.getAy(index);
            }
        }
    }

}
