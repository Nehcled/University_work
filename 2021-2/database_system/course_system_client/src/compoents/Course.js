import React, { Fragment } from 'react';
import { Button } from 'react-bootstrap';

class Course extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            courseData: this.props.courseData,
            transform: ["大神澪", "一", "二", "三", "四", "五", "六", "日"],
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
    sectionTransform(section) {
        const { transform } = this.state;
        return `星期${transform[Math.floor(section / 100)]}第${section % 100}節`;
    }

    render() {
        const { course_instance_id, course_name, description, required, section, teacher_name } = this.state.courseData;
        const courseStatus = "退選";
        return (
            <Fragment>
                <tr>
                    <td>{course_instance_id}</td>
                    <td>{course_name}</td>
                    <td>{description}</td>
                    <td>{teacher_name}</td>
                    <td>{required}</td>
                    <td>{this.sectionTransform(section)}</td>
                    <td><Button onClick={() => this.checkIsRequired()}>{courseStatus}</Button></td>
                </tr>
            </Fragment>
        )
    }
}

export default Course;