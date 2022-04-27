import React from 'react';
import { Button } from 'react-bootstrap';

class Course extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            courseData: this.props.courseData
        }
    }

    checkIsRequired() {
        const { course_instance_id, required } = this.state.courseData;
        if (required) {
            const confirm = window.confirm("此為必修課程，確定要退選嗎?")
            if (confirm) {
                this.props.onCourseSelect(course_instance_id);
            }
        } else {
            this.props.onCourseSelect(course_instance_id);
        }
    }

    render() {
        const { course_instance_id, course_id, course_name, discription, required, section, teacher_name } = this.state.courseData;
        const courseStatus = "退選";
        return (
            <div className='course'>
                <p>{course_instance_id}</p>
                <p>{course_id}</p>
                <p>{course_name}</p>
                <p>{discription}</p>
                <p>{teacher_name}</p>
                <p>{required}</p>
                <p>{section}</p>
                <Button onClick={() => this.checkIsRequired()}>{courseStatus}</Button>
            </div>
        )
    }
}

export default Course;