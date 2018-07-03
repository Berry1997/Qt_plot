import QtQuick 2.9

Item {
    id:trackline
    anchors.fill: parent
    property int x1
    property int y1
    property int x2
    property int y2
    property int index

    /*Item{
        Text {
            x:x1
            y:y1
            text: '>'+index
        }
        Text {
            x:x2
            y:y2
            text: index+'>'
        }
    }*/
    /*Canvas{
        anchors.fill: parent
        onPaint:{
            var ctx = getContext("2d")
            ctx.fillStyle = "transparent"
            ctx.lineWidth = 2;
            ctx.strokeStyle = "black"
            ctx.beginPath()
            ctx.moveTo(x1, y1)
            ctx.lineTo(x2, y2)
            ctx.stroke()
        }

    }*/
}
