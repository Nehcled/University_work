import React from 'react';
import { Stack, Button, Form, FormControl } from 'react-bootstrap'
import Course from './Course';

class StudentCourseTable extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            studentId: this.props.studentId,
            courseData: [],
        }
    }

    componentDidMount() {
        this.loadCourseData()
    }

    async loadCourseData() {
        const requestOptions = {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({
                studentId: this.state.studentId,
            })
        }

        const response = await fetch('/api/courseTable', requestOptions);
        if(!response.ok){
            alert("未搜尋到該學號，請重新輸入或聯絡客服人員!")
        }else{
            const json = await response.json();
            this.setState({ courseData: json });
        }
        
    }

    async handleCourseSelect(id) {
        const requestOptions = {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({
                studentId: this.state.studentId,
                courseInstanceId: id
            })
        }
        const response = await fetch('/api/deselect', requestOptions);
        const json = await response.json();
        switch (json.selectStatus) {
            case 1:
                this.loadCourseData();
                alert("退選成功");
                break;
            case 2:
                break;
            default:
                alert("System Error! 4044");
        }
    }

    handleChange(event) {
        this.setState({
            targetCoruseId: event.target.value,
        })
    }

    async handleSubmit(event) {
        event.target[0].value="";
        event.preventDefault();
        const requestOptions = {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({
                studentId: this.state.studentId,
                courseId: this.state.targetCoruseId
            })
        }
        const response = await fetch('/api/select', requestOptions);
        const json = await response.json();
        switch (json.selectStatus) {
            case 1:
                this.loadCourseData();
                alert("加選成功");
                break;
            case 2:
                alert("加選失敗，課程人數已滿!");
                break;
            case 3:
                alert("加選失敗，超出可選學分數!");
                break;
            case 4:
                alert("加選失敗，已選擇同名課程!");
                break;
            case 5:
                alert("加選失敗，課程衝堂!");
                break;
            default:
                alert("System Error! 4044");
        }
        console.log(event);
    }

    render() {
        const courseData = this.state.courseData || [];
        console.log(courseData);
        const courseList = courseData?.map((course, i) => (
            <Course key={i} courseData={course} onCourseSelect={(courseId) => this.handleCourseSelect(courseId)} />
        )) || [];
        console.log(courseList);
        return (
            <div className='course-table'>
                <h1>學生{this.state.studentId}已選擇的課程</h1>
                <div className='course-list'>
                    <Stack gap={courseList.length}>
                        {courseList}
                    </Stack>
                    <Form horizontal='true' onSubmit={(e) => this.handleSubmit(e)}>
                        <h1>加選課程</h1>
                        <div className='line-form'>
                            <FormControl className='form-control' type='text' placeholder='課程編號' onBlur={(e) => this.handleChange(e)} />
                            <Button className='button' variant='primary' type='submit'>加選</Button>
                        </div>
                    </Form>
                </div>

            </div>
        )
    }

}

export default StudentCourseTable;