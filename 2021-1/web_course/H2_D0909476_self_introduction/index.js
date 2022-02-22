let courses = document.querySelectorAll(".course");
let courses_info = course_info = {
    "id-1356": {
        course:"離散數學",
        teacher: "劉怡芬 助理教授",
        time:[[1,2],[4,3],[4,4]],
        teacher_link:"https://www.iecs.fcu.edu.tw/teacher/%E5%8A%89%E6%80%A1%E8%8A%AC/",
        teacher_img:"https://www.iecs.fcu.edu.tw/media/img/teacher/avatar/T27_YFLiu.jpg",
        classroom:["資電404","資電B04"]
    },
    "id-1362":{
        course:"Web程式設計",
        teacher: "薛念林 教授",
        time:[[1,3],[1,4],[2,8]],
        teacher_link:"https://www.iecs.fcu.edu.tw/teacher/nlhsueh/",
        teacher_img:"https://www.iecs.fcu.edu.tw/media/img/teacher/avatar/IMG_2906.png",
        classroom:["資電248","資電B02"]
    },
    "id-1370":{
        course:"密碼學",
        teacher: "李榮三 教授",
        time:[[1,8],[2,3],[2,4]],
        teacher_link:"https://www.iecs.fcu.edu.tw/teacher/leejs/",
        teacher_img:"https://www.iecs.fcu.edu.tw/media/img/teacher/avatar/LEo_2021a.png",
        classroom:["科航206"]
    },
    "id-1355":{
        course:"資料結構",
        teacher: "江庭輝 助理教授",
        time:[[2,6],[2,7],[3,2]],
        teacher_link:"https://www.iecs.fcu.edu.tw/teacher/%E6%B1%9F%E5%BA%AD%E8%BC%9D/",
        teacher_img:"https://www.iecs.fcu.edu.tw/media/img/teacher/avatar/T08030.jpg",
        classroom:["資電402","資電B04"]
    },
    "id-1354":{
        course:"資料結構實習",
        teacher: "江庭輝 助理教授",
        time:[[3,6],[3,7],[3,8]],
        teacher_link:"https://www.iecs.fcu.edu.tw/teacher/%E6%B1%9F%E5%BA%AD%E8%BC%9D/",
        teacher_img:"https://www.iecs.fcu.edu.tw/media/img/teacher/avatar/T08030.jpg",
        classroom:["圖213"]
    },
    "id-1353":{
        course:"通訊與網路概論",
        teacher: "洪維志 副教授",
        time:[[3,3],[3,4],[4,2]],
        teacher_link:"https://www.iecs.fcu.edu.tw/teacher/wchong/",
        teacher_img:"https://www.iecs.fcu.edu.tw/media/img/teacher/avatar/Hong.jpg",
        classroom:["資電B04","資電104"]
    },
    "id-0306":{
        course:"行銷管理",
        teacher: "李悅端 專任助理教授",
        time:[[4,7],[4,8],[4,9]],
        teacher_link:"https://marketing.fcu.edu.tw/teachers-detail/?id=T05064&unit_id=CB26",
        teacher_img:"",
        classroom:["商306"]
    },
    "id-3108":{
        course:"智慧生活與大數據物聯網應用",
        teacher: "王銘源",
        time:[[2,11],[2,12]],
        teacher_link:"",
        teacher_img:"",
        classroom:["紀302"]
    },
    "id-3058":{
        course:"打造自我品牌─職能加值課程",
        teacher: "蔡國鼎 專任助理教授",
        time:[[5,7],[5,8]],
        teacher_link:"https://genedu.fcu.edu.tw/teachers-detail/?id=T09060&unit_id=GE00",
        teacher_img:"",
        classroom:["育103"]
    },
    "id-1352":{
        course:"班級活動",
        teacher: "劉明機 副教授",
        time:[[1,10]],
        teacher_link:"https://www.iecs.fcu.edu.tw/teacher/%E5%8A%89%E6%98%8E%E6%A9%9F/",
        teacher_img:"https://www.iecs.fcu.edu.tw/media/img/teacher/avatar/pic_02726.jpg",
        classroom:[]
    },
    "id-3323":{
        course:"大二英文(一)",
        teacher: "Dawn-Marie Letourneau 專任助理教授",
        time:[[5,2],[5,3],[5,4]],
        teacher_link:"https://genedu.fcu.edu.tw/teachers-detail/?id=T10013&unit_id=GE00",
        teacher_img:"",
        classroom:["紀110"]
    }
}
let weekTag = ["星期一","星期二","星期三","星期四","星期五","星期六","星期日"];
let timeTag = ["第一節(08:10~09:00)","第二節(09:10~10:00)","第三節(10:10~11:00)","第四節(11:10~12:00)","第五節(12:10~13:00)","第六節(13:10~14:00)","第七節(14:10~15:00)","第八節(15:10~16:00)","第九節(16:10~17:00)","第十節(17:10~18:00)","第十一節(18:30~19:20)","第十二節(19:25~20:15)","第十三節(20:25~21:15)","第十四節(21:20~22:10)"];


let getTag = (tags) =>{
    let result = "<br>";
    for(let i = 0; i < tags.length; i++){
        result+=`${weekTag[tags[i][0]]} ${timeTag[tags[i][1]]}<br>`;
    }
    console.log(result);
    return result;
}

let printRoom = (classrooms) =>{
    let result = "";
    for(let i = 0; i< classrooms.length; i++){
        result+=classrooms[i];
        if(i+1<classrooms.length){
            result+=",";
        }
    }
    return result;
}

let showCourseInfo = (course_id) => {
    if(course_id<2)return;
    const { course, teacher, time, teacher_link, teacher_img, classroom } = courses_info[course_id[1]];
    let course_info_table = document.querySelector(".course-info").children;

    course_info_table[0].children[0].innerHTML = course;
    course_info_table[0].children[1].src = teacher_img;
    course_info_table[1].innerHTML = teacher;
    course_info_table[1].href = teacher_link;
    course_info_table[2].innerHTML = getTag(time);
    course_info_table[3].innerHTML = printRoom(classroom);
}


for (let i = 0; i < courses.length; i++) {
    courses[i].addEventListener("click", () => showCourseInfo(courses[i].classList));
}
let personal_img = document.querySelector(".personal-img");
personal_img.addEventListener("mouseover",() => {
    personal_img.src="./img/MioFlagTrick.gif";
});
personal_img.addEventListener("mouseout",() => {
    personal_img.src="./img/personal.jpg";
});