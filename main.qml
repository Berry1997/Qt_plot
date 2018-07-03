import QtQuick 2.9
import QtQuick.Window 2.2
//import QtQuick.Controls 1.4
import QtQuick.Controls 1.0
//import QtQuick.Controls 2.0
import Mymap 1.0
import QtQuick.Dialogs 1.3
ApplicationWindow {
    id:demowin
    visible: true
    width: 640
    height: 480
    color: "yellow"

    property string path
    property string mode
    MapElements{id:map;}
    MapElements{id:emp;} // refresh
    Drawarea{id:drawarea;mapread: map}
    //add menu bar
    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem {
                text: "Load"
                onTriggered: {
                    mode = "Load";
                    filedialog.open();

                }
            }
            MenuItem {
                text: "Save"
                onTriggered: {
                    if(path!="")
                        map.toXml(path);
                    else{
                        mode = "Save";
                        filedialog.open();
                    }

                }
            }
            MenuItem {
                text: "Save New"
                onTriggered: {
                    mode = "SaveN";
                    filedialog.open();
                }
            }
        }

    }
    MouseArea{
        id:fidpoint
        anchors.fill: drawarea
        onPressed: {
            switch(addstate.currentText){
            case 'Track':
                map.setTstart(mouseX,mouseY);
                break;
            case 'AGV':
                map.addAGV(mouseX,mouseY);
                break
            }
            console.log("press");
            console.log(addstate.pressed)
        }
        onReleased: {
            switch(addstate.currentText){
            case 'Track':
                map.addTrack(mouseX,mouseY);
                break;
            case 'AGV':
                break
            }
            console.log("release");
        }
    }
    ComboBox {
        id: addstate
        width: 100
        model: ["Nothing", "Track", "AGV" ]
    }
    Column{
        x: 5
        y: parent.height/2.0
        Text{
            id:numofT;
            text:'num of track:  ' + map.lenofTrack;
        }
        Text{
            id:numofA;
            text:'num of AGV:  ' + map.lenofAGV;}
    }

    Button{
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: 100
        text: qsTr("Setting")

        onClicked: {
            controlwin.num = map.lenofAGV
            controlwin.show()
            demowin.hide()
        }
    }
    onFocusObjectChanged: {
        // refresh draw area
        drawarea.mapread = emp
        drawarea.mapread = map
    }

    ApplicationWindow {
        id: controlwin
        visible: false
        width: 740
        height: 480
        color: "light green"
        Drawarea{id:showarea;x:200;mapread: map}
        property int num:0

        Button{
            id:doneB
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            width: bscroll.width
            text: qsTr("Done")

            onClicked: {
                controlwin.hide()
                demowin.show()
            }
        }
        ScrollView {
            id: bscroll
            width:200
            height: controlwin.height - doneB.height
            horizontalScrollBarPolicy:Qt.ScrollBarAlwaysOff
            Column{
                Repeater{
                    model:controlwin.num
                    UItag{
                        i:index
                        xx:map.getAx(index)
                        yy:map.getAy(index)
                        hl: drawarea.height
                        wl: drawarea.width
                        onUpdate: {
                            controlwin.updatedata(index,xx,yy)
                            console.log("update")
                            console.log(map.getAx(index))
                            console.log(map.getAy(index))
                        }
                    }
                }
                Text{
                    x:70
                    text: controlwin.num
                    color:'white'
                }
            }
        }
        function updatedata(i,x,y){
            console.log("function")
            map.setAGV(i,x,y)
            showarea.mapread = emp
            showarea.mapread = map
        }

        onClosing: {
            demowin.show()
        }
    }
    FileDialog{
        id:filedialog
        nameFilters: "*.xml"
        selectExisting:{
            if(mode=="Load")
                true;
            else
                false;
        }
        onAccepted: {
            path = fileUrl;
            //delete file://
            path = path.replace(/^(file:\/{2})/,"");
            // unescape html codes like '%23' for '#'
            if(mode=="Save" || mode=="SaveN")
                map.toXml(path);
            else
                map.fromXml(path);
        }
    }
}

