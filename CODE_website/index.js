
var rootRef = firebase.database().ref().child("bins");
  rootRef.on("child_added", snap => {
    var status = snap.child("STATUS 01").val();
    $("#t1").append("<tr><td>BIN 01</td><td>"+ status +"</td></tr>");

  });

  var rootRef = firebase.database().ref().child("bin1");
    rootRef.on('child_added', snap  => {
      var status1 = snap.child("STATUS 02").val();
      $("#t1").append("<tr><td>BIN 02</td><td>"+ status1 +"</td></tr>");

    });
